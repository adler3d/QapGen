#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>

std::string toLowerCaseSQLKeywords(const std::string& sql) {
    std::set<std::string> keywords = {
        "SELECT", "INSERT", "UPDATE", "DELETE", "FROM", "WHERE", "AND", "OR",
        "NOT", "IN", "BETWEEN", "LIKE", "IS", "NULL", "DISTINCT", "AS",
        "JOIN", "INNER", "LEFT", "RIGHT", "FULL", "ON", "USING", "GROUP",
        "HAVING", "ORDER", "BY", "ASC", "DESC", "UNION", "ALL", "CREATE",
        "DROP", "TABLE", "INDEX", "VIEW", "TRIGGER", "PROCEDURE", "FUNCTION",
        "CASE", "WHEN", "THEN", "ELSE", "END", "CAST", "CONVERT", "SET",
        "VALUES", "INTO", "EXISTS", "LIMIT", "OFFSET", "TRUE", "FALSE" , "IFNULL", "NULLIF"
    };

    std::string result;
    size_t i = 0;

    while (i < sql.size()) {
        char c = sql[i];

        // --- Пропуск однострочных комментариев ---
        if (c == '/' && i+1 < sql.size() && sql[i+1] == '/') {
            size_t end = sql.find('\n', i);
            if (end == std::string::npos) {
                result += sql.substr(i);
                break;
            }
            result += sql.substr(i, end - i);
            i = end;
            continue;
        }
        if (c == '-' && i+1 < sql.size() && sql[i+1] == '-') {
            size_t end = sql.find('\n', i);
            if (end == std::string::npos) {
                result += sql.substr(i);
                break;
            }
            result += sql.substr(i, end - i);
            i = end;
            continue;
        }

        // --- Многострочные комментарии ---
        if (c == '/' && i+1 < sql.size() && sql[i+1] == '*') {
            size_t end = sql.find("*/", i);
            if (end == std::string::npos) {
                result += sql.substr(i);
                break;
            }
            result += sql.substr(i, end - i + 2);
            i = end + 2;
            continue;
        }
        if (c == '{') {
            size_t end = sql.find('}', i);
            if (end == std::string::npos) {
                result += sql.substr(i);
                break;
            }
            result += sql.substr(i, end - i + 1);
            i = end + 1;
            continue;
        }
        if (c == '(' && i+1 < sql.size() && sql[i+1] == '*') {
            size_t end = sql.find("*)", i);
            if (end == std::string::npos) {
                result += sql.substr(i);
                break;
            }
            result += sql.substr(i, end - i + 2);
            i = end + 2;
            continue;
        }

        // --- SQL строки в '...' ---
        if (c == '\'') {
            size_t j = i + 1;
            while (j < sql.size()) {
                if (sql[j] == '\\') {
                    j += 2;
                } else if (sql[j] == '\'') {
                    j++;
                    // Удвоение: ''
                    if (j < sql.size() && sql[j] == '\'') {
                        j++;
                    } else {
                        break;
                    }
                } else {
                    j++;
                }
            }
            j = std::min(j, sql.size());
            result += sql.substr(i, j - i);
            i = j;
            continue;
        }

        // --- Идентификаторы в "..." или [...] ---
        if (c == '"' || c == '[') {
            char endChar = (c == '"') ? '"' : ']';
            size_t j = i + 1;
            while (j < sql.size() && sql[j] != endChar) {
                if (sql[j] == '\\') j += 2;
                else j++;
            }
            j = (j < sql.size()) ? j + 1 : sql.size();
            result += sql.substr(i, j - i);
            i = j;
            continue;
        }

        // --- Идентификаторы (слова) ---
        if (std::isalpha(c) || c == '_') {
            size_t j = i;
            while (j < sql.size() && (std::isalnum(sql[j]) || sql[j] == '_')) {
                j++;
            }
            std::string word = sql.substr(i, j - i);
            std::string upperWord = word;
            std::transform(upperWord.begin(), upperWord.end(), upperWord.begin(), ::toupper);

            if (keywords.find(upperWord) != keywords.end()) {
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                result += word; // уже в нижнем регистре, если нужно — toLower(word)
            } else {
                result += word;
            }
            i = j;
            continue;
        }

        // --- Всё остальное ---
        result += c;
        i++;
    }

    return result;
}