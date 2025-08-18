Procedure OnOkClick;
Begin
  Warning('2) '+['10','20','30','40','50'][2]); // 2) 30
  if action_type.variantvalue = null then action_type.Error('��������� ��������');
  if descr_result = '' then descr_result.Error('��������� ��������');
  Apply;
  Close;
End;

//4. ����� ���������� ����� ������ � ��������� "������" ����� ����� ��������� �����

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

  // ��� ���������� ����� ������� Group ����� �������� �� Null
  (Insert Into Clients(Name, Group) Values(:Name, :Group));

  // ��� ���������� ����� ������� Group ����� �������� �� Null
  (Update Clients Set Group=:Group Where Name=:Name);

  // ��� ���������� ����� ������� 0 ����� �������� �� Null
  (Update Clients Set Group=0 Where Name=:Name);

  // ��� ���������� ���� �������� Group �� ����� �������� �� Null
  (Update Clients Set Group=(:Group) Where Name=:Name);
  (Update Clients Set Group=:Group+0 Where Name=:Name);
  (Select 3 + 5);
  (Insert Into Clients(Name, Group) Select :Name, :Group);//�� ������ �������, ����� ������� ���������.
End;

Procedure OnCreate2;
Var
  Name  : String;
  Group : Integer;
Begin
  Name  := 'test';

  // ��� ���������� ����� ������� Null ����� �������� �� 0
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
  I := V; // ���������� ���� Variant ������ �������� � ���������� ����������� ����.
  Sin(V); // ���������� ���� Variant ������ �������� � ������� � ���������� ��������� ����.
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
    Warning('������ �������� IntegerField');
    If V Is IntegerLookupField Then 
      Warning('������ �������� IntegerLookupField. ��� �������� Text ����� ' + (V As IntegerLookupField).Text);
  End;

  If V Is StringField Then 
    Warning('������ �������� StringField');
End;
Procedure Test2(V : Variant);
Begin
  If V Is IntegerField Then
  Begin
    Warning('������ �������� IntegerField');
    If V Is IntegerLookupField Then 
      Warning('������ �������� IntegerLookupField. ��� �������� Text ����� ' + V.Text As String);
  End;

  If V Is StringField Then 
    Warning('������ �������� StringField');
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
  // ������ ������ A �������� 0 ���������
  A.Count := 10;
  // ������ ������ A �������� 10 ���������
End;

//Array[N] ��� Array.Item(N) - ������� �������

//������ � �������� ������� �������������� � ������� ��������� [], ���� � ������� ������ Item.

Procedure OnCreate8;
Var
  A : Array Of Variant;
  X : Variant;
  N : Integer;
Begin
  A.Count := 10;
  A[7] := 'A'; // ��������� �������� 7-��� ��������
  A.Item(4) := 1000; // ��������� �������� 4-��� ��������
  N := 4;
  A[N] := 4.1; // ��������� �������� 4-��� ��������
  X := A[7]; // ��������� �������� 7-��� �������� � ������ ����� �������� � ���������� X
  Warning(A[4] As String); // ��������� �������� 4-��� �������� � ����� ��� �� �����
End;
{
Array.Append - ���������� �������� � ������

��� ���������� �������� � ����� ������� ������������ ����� Append

A.Append(15);

��������� ������ ������� ������� � ������� ������� ����� Array.
����������� ����� ��������

� ����� ���������������� ������������� ����������� ���������� ���� ��������, ������� ����� ��������� � �������. ����� ���� � ��������� ����������� ��� Array Of Integer, Array Of Boolean, Array Of Dataset.
}
Procedure OnCreate9;
Var
  A : Array Of Integer;
Begin
  A.Count := 10;
  A[4] := 1000; // ��������� �������� 4-��� ��������
  A[7] := 'A'; // �� �� ������ ��������� � ������ ������
End;
{
����������� ��������

������� ����� ���������� � ������� ��������� :=.
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
������� []

��� �������� �������� �������� ������������� ������� []
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

//��� �������� ������� ����������� ������������� �������������� ���������

Procedure OnCreate11;
var
  X : Float;
  A : Array Of Float;
Begin
  X := 0.34;
  A := [X, X+2, X*X, Sin(X)];
End;
{
����������� �������� � ���������� ���� Array � Variant

��� ������� ����� ����������� � ���������� ���� Array ��� Variant. ��� ���� ��������� ����� �������, ��������� ������� �� ������ �� �������� ������.
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
  
  C := ['������','���'];
  V := C;
  Warning(ToStr(V)); // ������,���
End;
{
��� �������������� ����� �������������� ��� �������� ������������� ������� � ���������.
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
  
  C := ['������','���'];
  Print(C); // ������,���
End;

Procedure Print0(A : Array);
Begin
  Warning(ToStr(A));
End;
{
��� �� ����� ������ ����� ����������� � ���������� ���� Variant.

��� �������������� ��� �� ����� ������������ ��� �������� ������������� ������� � ���������, �� ��� ����, � ��������� ����� �������� � ����� ������ ��������. ��� ������ Variant �������� ��������, ��� Array.
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
  
  C := ['������','���'];
  V := C;
  Warning(V.Item(1) As String); // ���
End;
Type
  MyEnum = ( Apple, Avocado, Banana=100, Cashew, Cherry=100, Coconut, Fig, Grape, Guava, Kiwi );
  
Procedure OnCreate15;
Begin
  Warning(ToStr([Apple, Avocado, Banana, Cashew, Cherry, Coconut, Fig, Grape, Guava, Kiwi]));
  // ����� �������� �� �����: 0, 1, 100, 101, 100, 101, 102, 103, 104, 105
End;
