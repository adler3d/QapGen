cl.exe /O2 /std:c++20 /bigobj /EHsc QapGen/QapGen.cpp
link.exe "/SUBSYSTEM:WINDOWS" "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" QapGen.obj
move QapGen.exe Release
cd Release
QapGen.exe input.qapdsl.hpp
cd ..