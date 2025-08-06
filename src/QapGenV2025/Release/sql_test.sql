-- === 1. BETWEEN (простое) ===
select * from users where age between 18 and 65;

-- === 2. BETWEEN (с NOT) ===
select * from users where salary not between 30000 and 70000;

-- === 3. BETWEEN (вложенные выражения) ===
select * from products where price * tax between min_price and max_price;

-- === 4. BETWEEN (с вызовом функции) ===
select * from events where event_date between CURRENT_DATE and DATE_ADD(CURRENT_DATE, 7);

-- === 5. IN (список литералов) ===
select * from users where status in ('active', 'pending', 'suspended');

-- === 6. IN (числа) ===
select * from orders where user_id in (101, 205, 307, 409);

-- === !. IN (числа) ===
select * from orders where user_id in ("SELECT", 205, 307, 409);

-- === 7. IN (выражения) ===
select * from products where price in (min_price * 2, avg_price, max_price / 2);

-- === 8. IN (подзапрос) ===
select * from users where id in (select user_id from active_sessions);

-- === 9. IN (подзапрос с условием) ===
select * from products where category_id in (select id from categories where active = true);

-- === 10. IN (подзапрос с JOIN) ===
select * from customers where region_id in (
  select r.id from regions r join countries c on r.country_id = c.id where c.name = 'Russia'
);

-- === 11. IS NULL (простое) ===
select * from users where email is null;

-- === 12. IS NOT NULL ===
select * from users where phone is not null;

-- === 13. IS NULL (с выражением) ===
select * from logs where error_code is null and timestamp > '2025-01-01';

-- === 14. Комбинированные условия (AND/OR) ===
select * from employees where
  (salary between 50000 and 100000) and
  (department in ('IT', 'HR', 'Finance')) and
  (bonus is not null) or
  (status in (select status from temp_statuses));

-- === 15. Вложенные скобки и приоритеты ===
select * from data where
  (value in (1, 2, 3) or flag is null) and
  (score between (min_score + 10) and (max_score - 5));

-- === 16. NULLIF + IS NULL ===
select * from records where nullif(name, 'unknown') is not null;

-- === 17. IN + BETWEEN + IS NULL в одном выражении ===
select * from transactions where
  amount between 100 and 1000
  and user_id in (select id from vip_users)
  and description is not null;

-- === 18. NOT IN (подзапрос) ===
select * from users where id not in (select user_id from banned);

-- === 19. NOT IN (список) ===
select * from products where category not in ('deleted', 'draft');

-- === 20. Сложный CASE с IN и BETWEEN ===
select
  case
    when age between 13 and 19 then 'teen'
    when age in (20, 21, 22) then 'young adult'
    when status is null then 'unknown'
    else 'adult'
  end as age_group
from users;