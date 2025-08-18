#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

// ����������� ����� �������� ���� Pascal + SQL
const std::unordered_set<std::string> keywords = {
    // Pascal
    "begin", "end", "var", "procedure", "function", "if", "then", "else", "for", "to", "do",
    "while", "repeat", "until", "case", "of", "const", "type", "array", "record", "program",
    "boolean", "integer", "string", "real", "div", "mod", "and", "or", "not",
    "nil", "true", "false", "break", "continue", "shr", "shl", "xor",
    // sql
    "single", "select", "insert", "update", "delete", "from", "where", "and", "or",
    "not", "in", "between", "like", "is", "null", "distinct", "as",
    "join", "inner", "left", "right", "full", "on", "using", "group",
    "having", "order", "by", "asc", "desc", "union", "all", "create",
    "drop", "table", "index", "view", "trigger", "procedure", "function",
    "case", "when", "then", "else", "end", "cast", "convert", "set",
    "values", "into", "exists", "limit", "offset", "true", "false" , "ifnull", "nullif",
    "shr", "shl"
};

// ���������� ������ � ������� ��������
std::string to_lower(const std::string& s) {
    std::string res = s;
    std::transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}
// ���������� ������ � ����� � ������ �������� � ������� ��������, ���������� � ������
std::string capitalize(const std::string& s) {
    if (s.empty()) return s;
    return to_lower(s);
    std::string res = s;
    res[0] = toupper(res[0]);
    for (size_t i = 1; i < s.size(); ++i)
        res[i] = tolower(res[i]);
    return res;
}

enum State {
    CODE,
    SINGLE_QUOTE_STRING,
    DOUBLE_QUOTE_STRING,
    SINGLE_LINE_COMMENT,
    MULTI_LINE_COMMENT_CURLY,   // Pascal { ... }
    MULTI_LINE_COMMENT_PAREN    // Pascal (* ... *)
};

std::string process_code(const std::string& input) {
    State state = CODE;
    std::string output;
    std::string current_word;

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];

        // ��������� ��������� ����� � ������������
        if (state == CODE) {
            // ��������� ����� ������������
            if (c == '\'') {
                // ������ ��������� ������
                output += c;
                state = SINGLE_QUOTE_STRING;
                continue;
            }
            else if (c == '"') {
                // ������ ������� ������
                output += c;
                state = DOUBLE_QUOTE_STRING;
                continue;
            }
            else if (c == '/' && i + 1 < input.size() && input[i + 1] == '/') {
                // ������ ������������� ����������� //
                output += "//";
                i++;
                state = SINGLE_LINE_COMMENT;
                continue;
            }
            else if (c == '{') {
                // ������ �������������� ����������� Pascal {...}
                output += c;
                state = MULTI_LINE_COMMENT_CURLY;
                continue;
            }
            else if (c == '(' && i + 1 < input.size() && input[i + 1] == '*') {
                // ������ �������������� ����������� Pascal (* ... *)
                output += "(*";
                i++;
                state = MULTI_LINE_COMMENT_PAREN;
                continue;
            }

            // ��������� ���� � ����
            if (isalnum(c) || c == '_') {
                current_word += c; // ������������ ������� �����
            } else {
                // ����� �����
                if (!current_word.empty()) {
                    // ���������, ���� ����� ��������, ����������� � ������ �������
                    if (keywords.count(capitalize(current_word))) {
                        output += to_lower(current_word);
                    } else {
                        output += current_word;
                    }
                    current_word.clear();
                }
                // ��������� ������� ������ (������� �� ����� �����)
                output += c;
            }
        }
        else if (state == SINGLE_QUOTE_STRING) {
            output += c;
            if (c == '\'') {
                // �������� �� �������������� ������� ''
                if (i + 1 < input.size() && input[i + 1] == '\'') {
                    output += '\'';
                    i++;
                } else {
                    state = CODE;
                }
            }
        }
        else if (state == DOUBLE_QUOTE_STRING) {
            output += c;
            if (c == '"') {
                // ��������� ������� �������
                state = CODE;
            }
        }
        else if (state == SINGLE_LINE_COMMENT) {
            output += c;
            if (c == '\n') {
                state = CODE;
            }
        }
        else if (state == MULTI_LINE_COMMENT_CURLY) {
            output += c;
            if (c == '}') {
                state = CODE;
            }
        }
        else if (state == MULTI_LINE_COMMENT_PAREN) {
            output += c;
            if (c == '*' && i + 1 < input.size() && input[i + 1] == ')') {
                output += ')';
                i++;
                state = CODE;
            }
        }
    }

    // ���� ������� ������������� ����� ����� � ����� �����
    if (!current_word.empty()) {
        if (keywords.count(capitalize(current_word))) {
            output += to_lower(current_word);
        } else {
            output += current_word;
        }
    }

    return output;
}
/*
int main() {
    std::string pascal_code = R"(Procedure OnCreate2;
Var
  Name  : String;
  Group : Integer;
Begin
  Name  := 'test';
  Group := (Select Group From Clients Where Name=:Name);
  // ��� ����������� -- Select �� ��������
  { �������������
    ����������� Insert �� �������� }
  (* ��� ����������� Update �� �������� *)
  WriteLn('Select �� �������� � ������');
End;)";

    std::string processed = process_code(pascal_code);
    std::cout << processed << std::endl;
    return 0;
}*/
