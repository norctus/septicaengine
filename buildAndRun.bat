@echo off
set cwd=%cd%
echo Running build and run script ...
call pushd build && cmake --build . && pushd Debug && main.exe && cd %cwd%