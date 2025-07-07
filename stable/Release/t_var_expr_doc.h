t_var_expr:i_expr{
  t_sb_expr { ... }             // �������������� ����� []
  t_dd_part:i_part { ... }      // ������������� � ::
  t_template_part:i_part { ... }// ��������� ��������� <>
  t_arr { ... }                 // ������ ��������������
  t_item { ... }                // ��������� � ����� ����� .
  t_name name;                  // �������� ���
  TAutoPtr<i_part> tp?;         // (��������� �����) ��� (������������� � ::)
  TAutoPtr<t_arr> arr?;         // �������������� ����� �����
  vector<t_item> items?;        // ������������������ ��������� � ������
}
��������� �������� ���������� ��������� ��� ���������:
"t_some_template<int>::field[1][0].items[2]"

�������� ��������� "t_var_expr":
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

������������ ������:
t_var_expr
+- name: "t_some_template"
+- tp: t_template_part
�   +- expr: "int"
�   +- ddp: t_dd_part
�       +- arr:
�           +- t_elem
�               +- name: "field"
+- arr:
�   +- t_sb_expr (expr="1")
�   +- t_sb_expr (expr="0")
+- items:
    +- t_item
        +- name: "items"
        +- arr:
            +- t_sb_expr (expr="2")

