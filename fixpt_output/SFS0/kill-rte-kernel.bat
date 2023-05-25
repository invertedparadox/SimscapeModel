@echo off
REM Host: UFO-2544
DEL /S /Q /A:H "C:\Users\Inver\Documents\GitHub\SimscapeModel\fixpt_output\SFS0\.status\.status.txt" > NUL: 2>&1 
echo completed:stopped-by-user > "C:\Users\Inver\Documents\GitHub\SimscapeModel\fixpt_output\SFS0\.status\.status.txt"
echo Calling TASKKILL command on Polyspace process with PID 23284...
START /B /WAIT /HIGH TASKKILL /F /T /PID 23284 > NUL: 2>&1
timeout 2 > NUL
set currenttime=%time:~0,2%:%time:~3,2%:%time:~6,2%
for /f "usebackq tokens=*" %%a in (`echo %date%`) do set currentdate=%%a
for /f "usebackq tokens=*" %%b in (`whoami`) do set username=%%b
echo "Remark: Analysis stopped by %username% at %currenttime% %currentdate%. " >> "polyspace-dvo.log"
RMDIR /S /Q "C:\Users\Inver\AppData\Local\Temp\Polyspace\5AF4_1681830662" > NUL: 2>&1
DEL /S /Q "C:\Users\Inver\Documents\GitHub\SimscapeModel\fixpt_output\SFS0\*-journal" > NUL: 2>&1
