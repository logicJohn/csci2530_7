echo off
title My Test Batch File
::see the title at top.
echo Test file executed. > filename.txt
echo I am too lazy to write commands again and again
pause
(
echo 5
echo 1 2 9
echo 1 3 12 
echo 2 4 18
echo 2 3 8
echo 2 5 20
echo 3 5 15
echo 0
) | C:\Users\J\Documents\GitHub\csci2530\assignment5\testMst.exe

(
echo 2 
echo 1
echo 2
echo 4
echo 0
) | C:\Users\J\Documents\GitHub\csci2530\assignment5\testMst.exe

(
echo 2 1 2 7 8 7 78 8 78 7
echo 1
echo 2
echo 4
echo 0
) | C:\Users\J\Documents\GitHub\csci2530\assignment5\testMst.exe

SET /A test=%RANDOM% * 100 / 32768 + 1
echo %test%
SET /A test=%RANDOM% * 100 / 32768 + 1
echo %test%

FOR /L %%A IN (1,1,3) DO (
  ECHO %%A
)

pause
pause