@echo off
setlocal enabledelayedexpansion
set /a val=0
set filename=0
set /a init=0
set /a end=0

for /f "eol=; tokens=1,2,3 delims= " %%i in (param.txt) do (
set filename=%%i
set /a init=%%j
set /a end=%%k

)

for /l %%i in (%end%,-1,%init%) do (
if %init%==0 (set /a val=%%i+1) else (set val=%%i)  
ren %filename%%%i.in %filename%!val!.in
ren %filename%%%i.out %filename%!val!.ans
)

　　

　　　　　　　　　　　　　　　　　　　　　　　　　　　 
　　　　　　　　　 