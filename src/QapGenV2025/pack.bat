@FOR %%? IN ("%cd%") DO (@set FolderName=%%~n?)
"C:\Program Files\WinRAR\Rar.exe" a -k -s -r -m5 -ap%FolderName% -x@list.rarignore "%FolderName%.rar"