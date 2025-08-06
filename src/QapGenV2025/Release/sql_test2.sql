SELECT * FROM logs WHERE error_code IS NULL AND timestamp = inPUT;

SELECT
  u.id,
  u.name,
  CASE WHEN u.status = 'A' THEN 'Active' ELSE 'Inactive' END AS status_desc,
  COUNT(o.id) AS order_count
FROM users u
LEFT JOIN orders o ON u.id = o.user_id
WHERE u.created > '2023-01-01'
  AND u.id IN (SELECT user_id FROM active_sessions)
  AND u.age BETWEEN 18 AND 65
GROUP BY u.id, u.name, u.status
HAVING COUNT(o.id) > 0
ORDER BY order_count DESC, u.name ASC;

-- === 2::13. GROUP BY ===
SELECT status, COUNT(*) FROM users GROUP BY status;

-- === 1. BETWEEN (простое) ===
SELECT * FROM users WHERE age BETWEEN 18 AND 65;

-- === 2. BETWEEN (с NOT) ===
SELECT * FROM users WHERE salary NOT BETWEEN 30000 AND 70000;

-- === 3. BETWEEN (вложенные выражения) ===
SELECT * FROM products WHERE price * tax BETWEEN min_price AND max_price;

-- === 4. BETWEEN (с вызовом функции) ===
SELECT * FROM events WHERE event_date BETWEEN CURRENT_DATE AND DATE_ADD(CURRENT_DATE, 7);

-- === 5. IN (список литералов) ===
SELECT * FROM users WHERE status IN ('active', 'pending', 'suspended');

-- === 6. IN (числа) ===
SELECT * FROM orders WHERE user_id IN (101, 205, 307, 409);

-- === !. IN (числа) ===
SELECT * FROM orders WHERE user_id IN ('SELECT', :foo, 307, 409);

-- === 7. IN (выражения) ===
SELECT * FROM products WHERE price IN (min_price * 2, avg_price, max_price / 2);

-- === 8. IN (подзапрос) ===
SELECT * FROM users WHERE id IN (SELECT user_id FROM active_sessions);

-- === 9. IN (подзапрос с условием) ===
SELECT * FROM products WHERE category_id IN (SELECT id FROM categories WHERE active = true);

-- === 10. IN (подзапрос с JOIN) ===
SELECT * FROM customers WHERE region_id IN (
  SELECT r.id FROM regions r JOIN countries c ON r.country_id = c.id WHERE c.name = 'Russia'
);

-- === 11. IS NULL (простое) ===
SELECT * FROM users WHERE email IS NULL;

-- === 12. IS NOT NULL ===
SELECT * FROM users WHERE phone IS NOT NULL;

-- === 13. IS NULL (с выражением) ===
SELECT * FROM logs WHERE error_code IS NULL AND timestamp > '2025-01-01';

-- === 14. Комбинированные условия (AND/OR) ===
SELECT * FROM employees WHERE
  (salary BETWEEN 50000 AND 100000) AND
  (department IN ('IT', 'HR', 'Finance')) AND
  (bonus IS NOT NULL) OR
  (status IN (SELECT status FROM temp_statuses));

-- === 15. Вложенные скобки и приоритеты ===
SELECT * FROM data WHERE
  (value IN (1, 2, 3) OR flag IS NULL) AND
  (score BETWEEN (min_score + 10) AND (max_score - 5));

-- === 16. NULLIF + IS NULL ===
SELECT * FROM records WHERE NULLIF(name, 'unknown') IS NOT NULL;

-- === 17. IN + BETWEEN + IS NULL в одном выражении ===
SELECT * FROM transactions WHERE
  amount BETWEEN 100 AND 1000
  AND user_id IN (SELECT id FROM vip_users)
  AND description IS NOT NULL;

-- === 18. NOT IN (подзапрос) ===
SELECT * FROM users WHERE id NOT IN (SELECT user_id FROM banned);

-- === 19. NOT IN (список) ===
SELECT * FROM products WHERE category NOT IN ('deleted', 'draft');

-- === 20. Сложный CASE с IN и BETWEEN ===
SELECT
  CASE
    WHEN age BETWEEN 13 AND 19 THEN 'teen'
    WHEN age IN (20, 21, 22) THEN 'young adult'
    WHEN status IS NULL THEN 'unknown'
    ELSE 'adult'
  END AS age_group
FROM users;

/*part2*/

-- === 1. Простой SELECT ===
SELECT * FROM users;

-- === 2. SELECT с колонками и алиасами ===
SELECT id, name, email AS user_email FROM users;

-- === 3. SELECT с алиасом таблицы (без AS) ===
SELECT u.id, u.name FROM users u;

-- === 4. SELECT с алиасом таблицы (с AS) ===
SELECT u.id, u.name FROM users AS u;

-- === 5. WHERE с =, <>, <, >, <=, >= ===
SELECT * FROM users WHERE age >= 18 AND status <> 'inactive';

-- === 6. WHERE с AND, OR, NOT ===
SELECT * FROM users WHERE (age > 18 AND active = true) OR NOT (status = 'banned');

-- === 7. BETWEEN / NOT BETWEEN ===
SELECT * FROM products WHERE price BETWEEN 10 AND 100;
SELECT * FROM products WHERE price NOT BETWEEN 50 AND 200;

-- === 8. IN (список) ===
SELECT * FROM users WHERE status IN ('active', 'pending', 'suspended');

-- === 9. IN (числа) ===
SELECT * FROM orders WHERE user_id IN (101, 205, 307);

-- === 10. NOT IN ===
SELECT * FROM users WHERE id NOT IN (1, 2, 3);

-- === 11. LIKE, ILIKE (если поддерживается) ===
SELECT * FROM users WHERE name LIKE 'A%';
--SELECT * FROM users WHERE name LIKE '%ov' ESCAPE '\';

-- === 12. IS [NOT] NULL ===
SELECT * FROM logs WHERE error_code IS NULL;
SELECT * FROM users WHERE phone IS NOT NULL;

-- === 14. HAVING ===
SELECT department, AVG(salary) FROM employees GROUP BY department HAVING AVG(salary) > 50000;

-- === 15. ORDER BY (ASC/DESC) ===
SELECT * FROM users ORDER BY name ASC;
SELECT * FROM products ORDER BY price DESC, name ASC;

-- === 16. DISTINCT ===
SELECT DISTINCT country FROM users;

-- === 17. JOIN (INNER JOIN) ===
SELECT u.name, o.total FROM users u INNER JOIN orders o ON u.id = o.user_id;

-- === 18. JOIN (LEFT JOIN) ===
SELECT u.name, a.city FROM users u LEFT JOIN addresses a ON u.id = a.user_id;

-- === 19. JOIN (RIGHT JOIN) ===
SELECT p.name, s.amount FROM sales s RIGHT JOIN products p ON s.product_id = p.id;

-- === 20. FULL JOIN ===
SELECT e.name, d.name FROM employees e FULL JOIN departments d ON e.dept_id = d.id;

-- === 21. Много JOIN подряд ===
SELECT u.name, o.total, p.name FROM users u
  JOIN orders o ON u.id = o.user_id
  JOIN products p ON o.product_id = p.id;

-- === 22. Подзапрос в WHERE (IN) ===
SELECT * FROM users WHERE id IN (SELECT user_id FROM active_sessions);

-- === 23. Подзапрос в WHERE (с алиасом) ===
SELECT * FROM users WHERE id IN (SELECT u.id FROM users u WHERE u.active);

-- === 24. Подзапрос в FROM (с алиасом) ===
SELECT sub.id, sub.name FROM (SELECT id, name FROM users WHERE age > 18) AS sub;

-- === 25. Подзапрос в FROM (без AS) ===
SELECT temp.id FROM (SELECT id FROM users) temp;

-- === 26. UNION ===
SELECT name FROM users WHERE active
UNION
SELECT name FROM guests;

-- === 27. UNION ALL ===
SELECT status FROM users
UNION ALL
SELECT 'unknown' FROM dual;

-- === 28. INSERT INTO ... VALUES ===
INSERT INTO users (id, name, email) VALUES (1, 'Alice', 'alice@example.com');
/*
{"ok":false,"date":"2025.08.06 12:18:34"}@@@{"offset":6027}
{"line":187,"pos":18}
"insert into users (id, name, email) values (1, \'Alice\', \'alice@example.com\');\n" ...
"insert into users ^-- error
lexer: t_insert_stat; expected: TAutoPtr<i_insert_body>,"sv"
*/
-- === 29. INSERT INTO ... VALUES (много строк) ===
INSERT INTO points VALUES (1, 2), (3, 4), (5, 6);

-- === 30. INSERT INTO ... SELECT ===
INSERT INTO backup_users SELECT * FROM users WHERE last_login < '2024-01-01';

-- === 31. UPDATE с SET ===
UPDATE users SET email = 'new@example.com' WHERE id = 1;

-- === 32. UPDATE с несколькими полями ===
UPDATE users SET name = 'Bob', age = 30 WHERE id = 1;

-- === 33. UPDATE с выражением ===
UPDATE products SET price = price * 1.1 WHERE category = 'electronics';

-- === 34. DELETE ===
DELETE FROM users WHERE id = 1;

-- === 35. DELETE с условием ===
DELETE FROM sessions WHERE last_active < '2024-01-01';

-- === 36. CASE (простой) ===
SELECT
  CASE WHEN age < 18 THEN 'minor'
       WHEN age < 65 THEN 'adult'
       ELSE 'senior'
  END AS age_group
FROM users;

-- === 37. CASE (с выражением) ===
SELECT
  CASE status
    WHEN 'A' THEN 'Active'
    WHEN 'I' THEN 'Inactive'
    ELSE 'Unknown'
  END
FROM users;

-- === 38. CASE с NULL ===
SELECT
  CASE WHEN status IS NULL THEN 'No status'
       ELSE 'Has status'
  END
FROM users;

-- === 39. Агрегатные функции: COUNT, SUM, AVG, MIN, MAX ===
SELECT
  COUNT(*) AS cnt,
  SUM(salary) AS total,
  AVG(age) AS avg_age,
  MIN(created) AS first,
  MAX(updated) AS last
FROM employees;

-- === 40. COUNT(*) и COUNT(expr) ===
SELECT COUNT(*) FROM users;
SELECT COUNT(email) FROM users;

-- === 41. NULLIF и IFNULL ===
SELECT NULLIF(name, 'default') FROM users;
SELECT IFNULL(name, 'anonymous') FROM users;

-- === 42. Выражения с приоритетами ===
SELECT (a + b) * c FROM xvalues;
SELECT a + b * c FROM valuesx;

-- === 43. Строковые литералы с экранированием ===
SELECT 'It''s a test' FROM dual;
SELECT 'New\nLine\tTab' FROM dual;
SELECT 'Hex: \x41' FROM dual;
SELECT 'Unicode: \u0041' FROM dual;

-- === 44. Числа: целые, дробные, экспоненциальные ===
SELECT 123, 3.14, .5, 1e10, 1.5e-5 FROM dual;

-- === 45. Параметры (host variables) ===
SELECT * FROM users WHERE id = :user_id;
UPDATE users SET name = :name WHERE id = :id;

-- === 46. Комментарии: -- и /* */ ===
-- Это однострочный комментарий
SELECT * FROM users; /* Это многострочный
комментарий */

-- === 47. Вложенные подзапросы ===
SELECT * FROM users WHERE id IN (
  SELECT user_id FROM orders WHERE total > (
    SELECT AVG(total) FROM orders
  )
);

-- === 48. Подзапрос в IN с JOIN ===
SELECT * FROM customers WHERE region_id IN (
  SELECT r.id FROM regions r JOIN countries c ON r.country_id = c.id WHERE c.name = 'Russia'
);

-- === 49. NOT IN с подзапросом ===
SELECT * FROM users WHERE id NOT IN (SELECT user_id FROM banned);

-- === 50. Полный сложный запрос ===
SELECT
  u.id,
  u.name,
  CASE WHEN u.status = 'A' THEN 'Active' ELSE 'Inactive' END AS status_desc,
  COUNT(o.id) AS order_count
FROM users u
LEFT JOIN orders o ON u.id = o.user_id
WHERE u.created > '2023-01-01'
  AND u.id IN (SELECT user_id FROM active_sessions)
  AND u.age BETWEEN 18 AND 65
GROUP BY u.id, u.name, u.status
HAVING COUNT(o.id) > 0
ORDER BY order_count DESC, u.name ASC;