@echo off
set CURRENT_DIR=%cd%
echo Running build and run script ...
if not exist "build" (
    mkdir build && pushd build && cmake .. && popd
)
call pushd build && cmake --build . && pushd bin && pushd Debug && main.exe
cd %CURRENT_DIR%