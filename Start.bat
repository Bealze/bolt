@echo off 
cls 

set version=1.0 
set wat=DayZ Server: Bolt Mod 

title %wat% Watchdog 

cd C:\SteamLibrary\steamapps\common\DayZServer

:watchdog 
color 3
echo Thanks for using DayZ Bolt mod
echo Created by @mov3ax
echo Special Thanks to folowing people
echo @Arkensor Code Snippets from Offline Mode
echo @BohemiaInteract / @DayZ for This Great Game
echo @FIDOv Help With Tools
echo @erikbc For Generated Server API
echo @dayz_survivor3 and @uyke for Spawn Points

echo (%time%) %wat% started. 
start "Dayz_SA" /wait /affinity FF /high "DayZServer_x64.exe" -config=serverDZ.cfg 

echo (%time%) %wat% closed or crashed, restarting. 
goto watchdog