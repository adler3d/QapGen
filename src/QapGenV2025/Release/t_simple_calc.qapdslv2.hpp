t_simple_calc{
  //обьявляемы и реализуем вложенные в t_simple_calc лексеры
  t_term{
    TAutoPtr<i_term> value; // вызываем парсинг полиморфной ноды/лексера.
  }
  t_number:i_term{
    t_ext{
      "." // жрём точечку.
      string v=any(gen_dips("09")); // жрём всё от 0 до 9 пока оно есть.
    }
    t_impl{
      string bef=any(gen_dips("09"));
      TAutoPtr<t_ext> ext?; // парсим опциональный t_ext
    }
    string value=str<t_impl>(); // парсим t_impl и сохраняем его в строку.
  }
  t_divmul{
    t_elem{
      string oper=any_str_from_vec(split("/,*",",")); // сжираем / или *
      t_term expr; // запускаем полиморфа который есть скобки и числа
    }
    t_term first;
    vector<t_elem> arr?; // запускаем опциональный парсинг массива t_elem
  }
  t_addsub{
    t_elem{
      string oper=any_str_from_vec(split("+,-",",")); // сжираем + или -
      t_divmul expr;
    }
    t_divmul first; // парсим t_divmul, т.к у него выше приоретет
    vector<t_elem> arr?; // теперь опционально все остальные
  }
  t_scope:i_term{
    "(" // едим скобку
    t_addsub value; // начинаем с + или -,т.к у них низкий приортет
    ")" // ещё скобочку
  }
  // точка входа:
  t_addsub value; // парсим t_addsub
}