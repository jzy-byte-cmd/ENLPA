@echo off
cd target
set name=list.txt
set path=%~dp0%name%
dir /a:-d /b >%path%