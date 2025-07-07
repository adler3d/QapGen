t_simple_calc{
  //���������� � ��������� ��������� � t_simple_calc �������
  t_term{
    TAutoPtr<i_term> value; // �������� ������� ����������� ����/�������.
  }
  t_number:i_term{
    t_ext{
      "." // ��� �������.
      string v=any(gen_dips("09")); // ��� �� �� 0 �� 9 ���� ��� ����.
    }
    t_impl{
      string bef=any(gen_dips("09"));
      TAutoPtr<t_ext> ext?; // ������ ������������ t_ext
    }
    string value=str<t_impl>(); // ������ t_impl � ��������� ��� � ������.
  }
  t_divmul{
    t_elem{
      string oper=any_str_from_vec(split("/,*",",")); // ������� / ��� *
      t_term expr; // ��������� ��������� ������� ���� ������ � �����
    }
    t_term first;
    vector<t_elem> arr?; // ��������� ������������ ������� ������� t_elem
  }
  t_addsub{
    t_elem{
      string oper=any_str_from_vec(split("+,-",",")); // ������� + ��� -
      t_divmul expr;
    }
    t_divmul first; // ������ t_divmul, �.� � ���� ���� ���������
    vector<t_elem> arr?; // ������ ����������� ��� ���������
  }
  t_scope:i_term{
    "(" // ���� ������
    t_addsub value; // �������� � + ��� -,�.� � ��� ������ ��������
    ")" // ��� ��������
  }
  // ����� �����:
  t_addsub value; // ������ t_addsub
}