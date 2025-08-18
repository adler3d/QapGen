Procedure OnOkClick;
Begin
  Warning('2) '+['10','20','30','40','50'][2]); // 2) 30
  if action_type.variantvalue = null then action_type.Error('Заполните значение');
  if descr_result = '' then descr_result.Error('Заполните значение');
  Apply;
  Close;
End;

//4. Вызов упрощенной формы задачи в документе "Запрос" делай через модальную форму

Procedure OnActionrecordClick;
var f:variant;
Begin
  if id=0 then Save;
  f := ModalForm('ide_doc_simple_taskForm',emAdd,null,'after_simple_task_add');
End;

Procedure after_simple_task_add(F:Variant;okv:boolean);
begin
  if okv then
  begin
  (insert into ide_doc_task (doc_date,Name,source_type,source_key,Employee,action_type,task_result,create_date,author,date_result,descr_result)
  values(:date(),:(single Name from ide_dir_task_action_type where id=:F.Item('action_type').value as integer),:3,:id,:ide_GP.GetEmployeeId,:action_type,:1,:now(),:ide_GP.GetEmployeeId,:now(),:F.Item('descr_result').value as String));
  end;	
end;

Procedure after_simple_task_add_pretty(F:Variant;okv:boolean);
begin
  if okv then
  begin
  (
    insert into ide_doc_task (
      doc_date,Name,source_type,source_key,Employee,action_type,task_result,create_date,author,date_result,descr_result
    )
    values(
      :date(),:(
        single
          Name from ide_dir_task_action_type
        where id=:F.Item('action_type').value as integer
      ),:3,:id,:ide_GP.GetEmployeeId,:action_type,:1,:now(),:ide_GP.GetEmployeeId,:now(),:F.Item('descr_result').value as String
    )
  );
  end;	
end;

Procedure OnCreate;
Var
  Name  : String;
  Group : Integer;
Begin
  Name  := 'test';
  Group := 0;

  // При выполнении этого запроса Group будет заменено на Null
  (Insert Into Clients(Name, Group) Values(:Name, :Group));

  // При выполнении этого запроса Group будет заменено на Null
  (Update Clients Set Group=:Group Where Name=:Name);

  // При выполнении этого запроса 0 будет заменено на Null
  (Update Clients Set Group=0 Where Name=:Name);

  // При выполнении этих запросов Group НЕ БУДЕТ заменено на Null
  (Update Clients Set Group=(:Group) Where Name=:Name);
  (Update Clients Set Group=:Group+0 Where Name=:Name);
  (Select 3 + 5);
  (Insert Into Clients(Name, Group) Select :Name, :Group);//из пустой таблицы, нужно сделать поддержку.
End;

Procedure OnCreate2;
Var
  Name  : String;
  Group : Integer;
Begin
  Name  := 'test';

  // При выполнении этого запроса Null будет заменено на 0
  Group := (Single Group From Clients Where Name=:Name);
End;

Procedure OnCreate3;
Var
  X, W : Variant;
  S : String;
Begin
  X := CreateOleObject('Excel.Application');
  X._Dynamic('Visible') := True;
  S := 'WorkBooks';
  W := X._Dynamic[S]._Dynamic('Open','c:\test.xls');
  W._Dynamic('Close');
  X._Dynamic('Quit');
End;

Procedure OnCreate4;
Var
  V : Variant;
  I : Integer;
Begin
  V := 1;
  I := V; // Переменную типа Variant нельзя записать в переменную конкретного типа.
  Sin(V); // Переменную типа Variant нельзя передать в функцию с аргументом отличного типа.
End;
Procedure OnCreate5;
Var
  V : Variant;
  I : Integer;
Begin
  V := 1;
  I := V As Integer;
  Sin(V As Integer);
End;
Procedure OnCreate6;
Var
  V : Variant;
  I : Integer;
Begin
  V := '1';
  I := V As Integer;
  Sin(V As Integer);
End;
Procedure Test(V : Field);
Begin
  If V Is IntegerField Then
  Begin
    Warning('Объект является IntegerField');
    If V Is IntegerLookupField Then 
      Warning('Объект является IntegerLookupField. Его свойство Text равно ' + (V As IntegerLookupField).Text);
  End;

  If V Is StringField Then 
    Warning('Объект является StringField');
End;
Procedure Test2(V : Variant);
Begin
  If V Is IntegerField Then
  Begin
    Warning('Объект является IntegerField');
    If V Is IntegerLookupField Then 
      Warning('Объект является IntegerLookupField. Его свойство Text равно ' + V.Text As String);
  End;

  If V Is StringField Then 
    Warning('Объект является StringField');
End;
Procedure OnCreate7;
Var
  A : Array Of Variant;
Begin
End;
Procedure OnCreate;
Var
  A : Array Of Variant;
Begin
  // Сейчас массив A содержит 0 элементов
  A.Count := 10;
  // Теперь массив A содержит 10 элементов
End;

//Array[N] или Array.Item(N) - Элемент массива

//Доступ к элементу массива осуществляется с помощью оператора [], либо с помощью метода Item.

Procedure OnCreate8;
Var
  A : Array Of Variant;
  X : Variant;
  N : Integer;
Begin
  A.Count := 10;
  A[7] := 'A'; // Установка значения 7-ого элемента
  A.Item(4) := 1000; // Установка значения 4-ого элемента
  N := 4;
  A[N] := 4.1; // Установка значения 4-ого элемента
  X := A[7]; // Получение значения 7-ого элемента и запись этого значения в переменную X
  Warning(A[4] As String); // Получение значения 4-ого элемента и вывод его на экран
End;
{
Array.Append - Добавление элемента в массив

Для добавления элемента в конец массива предназначен метод Append

A.Append(15);

Остальные методы массива описаны в разделе справки Класс Array.
Ограничение типов значений

В языке программирования предусмотрена возможность ограничить типы значений, которые можно сохранить в массиве. Такие типы в программе описываются как Array Of Integer, Array Of Boolean, Array Of Dataset.
}
Procedure OnCreate9;
Var
  A : Array Of Integer;
Begin
  A.Count := 10;
  A[4] := 1000; // Установка значения 4-ого элемента
  A[7] := 'A'; // Вы не можете сохранить в массив строку
End;
{
Копирование массивов

Массивы можно копировать с помощью оператора :=.
}
Procedure OnCreate10;
Var
  A, B : Array Of Integer;
Begin
  A.Count := 5;
  A[3] := 100;
  B := A;
  A[3] := 200;
  Warning('A=['+ToStr(A)+'] B=['+ToStr(B)+']'); // A=[0,0,0,200,0] B=[0,0,0,100,0]
End;
{
Команда []

Для удобного описания массивов предназначена команда []
}
Procedure OnCreate11;
var
  A : Array Of String;
  I : Integer;
Begin
  A := ['10','20','30','40','50'];
  Warning('1) '+A[2]); // 1) 30
  
  Warning('2) '+['10','20','30','40','50'][2]); // 2) 30

  I := ['10','20','30','40','50'].Find('40');
  Warning('3) '+IntToStr(I)); // 3) 3
End;

//При описании массива допускается использование арифметических выражений

Procedure OnCreate11;
var
  X : Float;
  A : Array Of Float;
Begin
  X := 0.34;
  A := [X, X+2, X*X, Sin(X)];
End;
{
Копирование массивов в переменные типа Array и Variant

Все массивы можно скопировать в переменные типа Array или Variant. При этом создается копия массива, изменение которой не влияет на исходный массив.
}
Procedure OnCreate12;
Var
  A : Array Of Variant;
  B : Array Of Integer;
  C : Array Of String;
  V : Array;
Begin
  A := [12,'A',-0.12];
  V := A;
  Warning(ToStr(V)); // 12,A,-0.12
  
  B := [10,20,30];
  V := B;
  Warning(ToStr(V)); // 10,20,30
  
  C := ['Привет','мир'];
  V := C;
  Warning(ToStr(V)); // Привет,мир
End;
{
Это преобразование может использоваться для передачи произвольного массива в процедуру.
}
Procedure OnCreate13;
Var
  A : Array Of Variant;
  B : Array Of Integer;
  C : Array Of String;
Begin
  A := [12,'A',-0.12];
  Print(A); // 12,A,-0.12
  
  B := [10,20,30];
  Print(B); // 10,20,30
  
  C := ['Привет','мир'];
  Print(C); // Привет,мир
End;

Procedure Print0(A : Array);
Begin
  Warning(ToStr(A));
End;
{
Так же любой массив можно скопировать в переменную типа Variant.

Это преобразование так же можно использовать для передачи произвольного массива в процедуру, но при этом, в процедуру можно передать и любое другое значение. Тип данных Variant работает медленее, чем Array.
}
Procedure OnCreate14;
Var
  A : Array Of Variant;
  B : Array Of Integer;
  C : Array Of String;
  V : Variant;
Begin
  A := [12,'A',-0.12];
  V := A;
  Warning(V.Item(1) As String); // A
  
  B := [10,20,30];
  V := B;
  Warning(V.Item(1) As String); // 20
  
  C := ['Привет','мир'];
  V := C;
  Warning(V.Item(1) As String); // мир
End;
Type
  MyEnum = ( Apple, Avocado, Banana=100, Cashew, Cherry=100, Coconut, Fig, Grape, Guava, Kiwi );
  
Procedure OnCreate15;
Begin
  Warning(ToStr([Apple, Avocado, Banana, Cashew, Cherry, Coconut, Fig, Grape, Guava, Kiwi]));
  // Будет выведено на экран: 0, 1, 100, 101, 100, 101, 102, 103, 104, 105
End;
