setlocal enabledelayedexpansion
rem �������� ���������� ��� ������
set ERRORLEVEL=0
cl.exe /std:c++17 /bigobj /EHsc /DQAP_DEBUG /Zi /Od /DEBUG /Fd"QapGen.pdb" QapGen/QapGen.cpp
if errorlevel 1 (
  echo err, stop working
  exit /b %errorlevel%
)
link.exe /DEBUG "/SUBSYSTEM:WINDOWS" "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" QapGen.obj
if errorlevel 1 (
  echo err, stop working
  exit /b %errorlevel%
)
move QapGen.exe Release
cd Release
QapGen.exe input.qapdsl.hpp
if errorlevel 1 (
  echo err, stop working
  exit /b %errorlevel%
)
dir
cd ..