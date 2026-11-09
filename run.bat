@echo off
g++ -O2 -o gen.exe gen.cpp
g++ -O2 -o sol.exe sol.cpp
g++ -O2 -o brute.exe brute.cpp

set cnt=0
:run
set /a cnt+=1
gen > in
sol < in > out
brute < in > ok
fc out ok > nul
if ErrorLevel 1 (
    echo WRONG ANSWER on test %cnt%
    exit /b
)
echo Test %cnt% passed
goto run