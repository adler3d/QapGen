cl.exe /O2 /std:c++17 /bigobj /EHsc SimpleCalc/SimpleCalc.cpp
link.exe "/SUBSYSTEM:CONSOLE" "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" QapGen.obj
move SimpleCalc.exe Release
cd Release
SimpleCalc.exe
cd ..