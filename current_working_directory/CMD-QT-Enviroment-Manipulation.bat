@echo off
cd C:\Qt\Tools\QtCreator\bin

qtcreator -help
#C:\Qt\MaintenanceTool.exe to update or deletee 
# Open a project from a directory : C:\qtcreator\bin>qtcreator.exe C:\Examples\alarms
#qtcreator -help


cmd /k




Press Win + S and search for "Environment Variables."

Edit the Path variable and add:


C:\Program Files\MySQL\MySQL Connector C 6.1\bin

Restart your IDE or PC after making these changes.



verificat if file exist :   

cd C:\Qt\6.8.1\mingw_64\bin
dir qmake.exe
----------------------------------------------------------


PATH environment variable. This command temporarily sets the PATH for the current session:

sh
set PATH=%PATH%;C:\Qt\6.8.1\mingw_64\bin
For a Permanent Solution
To make this change permanent, you can use the setx command:

sh
setx PATH "%PATH%;C:\Qt\6.8.1\mingw_64\bin"
Instructions for Using the Command:

-----------------------------------------------------
setx PATH "%PATH%;C:\Qt\6.8.1\mingw_64\bin"
------------------------------------------------------

setx PATH "%PATH%;C:\Qt\6.8.1\mingw_64\bin"
qmake --version
--------------------------------------------------------