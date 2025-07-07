@del Release\Sgon.exe
rem call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvars64.bat"
@set "solution=QapGen.sln"
@del /Q QapGen\Release
@del /Q Release\QapGen.*
node time.js
MSBuild.exe %solution% /p:configuration=Release /p:platform=Win32
node time.js
pause
cd Release
Sgon.exe
pause