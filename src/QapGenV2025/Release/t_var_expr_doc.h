t_var_expr:i_expr{
  t_sb_expr { ... }             // индексирование через []
  t_dd_part:i_part { ... }      // квалификаторы с ::
  t_template_part:i_part { ... }// шаблонные параметры <>
  t_arr { ... }                 // массив индексирований
  t_item { ... }                // обращение к члену через .
  t_name name;                  // основное имя
  TAutoPtr<i_part> tp?;         // (шаблонная часть) или (квалификаторы с ::)
  TAutoPtr<t_arr> arr?;         // индексирования после имени
  vector<t_item> items?;        // последовательность обращений к членам
}
Аккуратно распишем правильную структуру для выражения:
"t_some_template<int>::field[1][0].items[2]"

Итоговая структура "t_var_expr":
t_var_expr:i_expr{
  name = "t_some_template"
  tp = t_template_part {
    expr = "int"
    ddp = t_dd_part {
      arr = [
        t_elem {
          name = "field"
        }
      ]
    }
  }
  arr = t_arr {
    arr = [
      t_sb_expr { expr = "1" },
      t_sb_expr { expr = "0" }
    ]
  }
  items = [
    t_item {
      name = "items"
      arr = t_arr {
        arr = [
          t_sb_expr { expr = "2" }
        ]
      }
    }
  ]
}

Визуализация дерева:
t_var_expr
+- name: "t_some_template"
+- tp: t_template_part
¦   +- expr: "int"
¦   +- ddp: t_dd_part
¦       +- arr:
¦           +- t_elem
¦               +- name: "field"
+- arr:
¦   +- t_sb_expr (expr="1")
¦   +- t_sb_expr (expr="0")
+- items:
    +- t_item
        +- name: "items"
        +- arr:
            +- t_sb_expr (expr="2")

