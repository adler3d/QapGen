typedef uint32_t U32;
typedef U32 t_symbol_v3;

// Вспомогательная функция: получить длину UTF-8 символа по первому байту
inline int utf8_char_len(uint8_t c) {
    if ((c & 0x80) == 0) return 1;
    if ((c & 0xE0) == 0xC0) return 2;
    if ((c & 0xF0) == 0xE0) return 3;
    if ((c & 0xF8) == 0xF0) return 4;
    return 1;
}

// Создать t_symbol_v3 из начала UTF-8 строки
t_symbol_v3 make_symbol_v3(const char* p) {
    t_symbol_v3 data = 0;
    int len = utf8_char_len(p[0]);
    for (int i = 0; i < len && i < 4; ++i) {
        data |= (t_symbol_v3)(uint8_t)p[i] << (i * 8);
    }
    return data;
}

class QapStrFinderUni {
public:
    struct t_cmd {
        int pos = -1;           // позиция в ключевом слове
        int next_line = -1;     // следующее состояние
        int arr_id = -1;        // индекс в vecs
        int last_pos = -1;      // длина полного совпадения
    };

    struct t_line {
        // Заменяем массив[256] на map по t_symbol_v3
        std::unordered_map<t_symbol_v3, t_cmd> cmds;
    };

public:
    std::vector<std::vector<int>> vecs;       // списки ID ключевых слов
    std::vector<std::vector<t_symbol_v3>> keywords; // ключевые слова как vector<t_symbol_v3>
    std::vector<t_line> lines;                // trie

public:
    static QapStrFinder fromArr(const std::vector<std::string>& arr) {
        QapStrFinder tmp;
        tmp.build(arr);
        return tmp;
    }

    void build(const std::vector<std::string>& arr) {
        vecs.reserve(1024 * 8);
        qap_add_back(lines); // lines[0] — корень

        for (int i = 0; i < arr.size(); i++) {
            add_keyword(arr[i]);
        }
    }

    void add_keyword(const std::string& keyword_utf8) {
        auto id = keywords.size();

        // Конвертируем строку в vector<t_symbol_v3>
        std::vector<t_symbol_v3> symbols;
        const char* p = keyword_utf8.c_str();
        const char* end = p + keyword_utf8.size();
        while (p < end) {
            symbols.push_back(make_symbol_v3(p));
            int len = utf8_char_len(p[0]);
            p += len;
        }

        keywords.push_back(symbols);

        int state = 0;
        int last_pos = -1;
        for (int i = 0; i < symbols.size(); i++) {
            state = add(state, id, i, last_pos);
        }
    }

    int add(int line_id, int keyword_id, int pos, int& last_pos) {
        const auto next_pos = pos + 1;
        const auto& kw = keywords[keyword_id];
        const t_symbol_v3 c = kw[pos];
        bool eow = (next_pos == kw.size());

        auto& cmd_map = lines[line_id].cmds;
        auto it = cmd_map.find(c);
        int next_line = (it != cmd_map.end()) ? it->second.next_line : -1;

        bool need_new_line = (next_line == -1) && !eow;
        if (need_new_line) {
            next_line = lines.size();
            qap_add_back(lines);
        }

        auto& ex = cmd_map[c];
        if (ex.arr_id < 0) {
            ex.arr_id = vecs.size();
            qap_add_back(vecs);
        }

        auto& arr = vecs[ex.arr_id];
        arr.push_back(keyword_id);

        if (ex.pos == -1) {
            ex.pos = pos;
        }
        QapAssert(ex.pos == pos);

        ex.next_line = next_line;

        if (eow) {
            QapAssert(ex.last_pos != next_pos);
            ex.last_pos = next_pos;
            QapAssert(last_pos != next_pos);
            last_pos = next_pos;
        }

        if (last_pos != -1) {
            ex.last_pos = last_pos;
        }
        if (ex.last_pos != -1) {
            last_pos = ex.last_pos;
        }

        return ex.next_line;
    }
};

bool go_any_str_from_vec(string& ref, const QapStrFinderUni& arr) {
    auto& body = ref;
    auto n = mem.size();
    if (pos >= n) return false;

    const char* p = &mem[pos];
    const char* e = p + n;

    int state = 0;
    int last_pos = -1;

    while (p < e) {
        // Создаём t_symbol_v3 из текущей позиции
        if (p + 4 > e && utf8_char_len(p[0]) > (e - p)) {
            // Не хватает байт для полного символа
            break;
        }
        t_symbol_v3 c = make_symbol_v3(p);
        int char_len = utf8_char_len(p[0]);

        auto& cmd_map = arr.lines[state].cmds;
        auto it = cmd_map.find(c);
        if (it == cmd_map.end()) {
            if (last_pos == -1) return false;
            body = mem.substr(pos, last_pos);
            pos += body.size();
            return true;
        }

        auto& ex = it->second;
        state = ex.next_line;
        if (ex.last_pos != -1) {
            last_pos = ex.last_pos;
        }

        if (state == -1) {
            if (last_pos == -1) return false;
            body = mem.substr(pos, last_pos);
            pos += body.size();
            return true;
        }

        p += char_len;
    }

    if (last_pos == -1) return false;
    body = mem.substr(pos, last_pos);
    pos += body.size();
    return !body.empty();
}