@echo off
set CURRENT_DIR=%cd%
echo Running build and run script ...
if not exist "build" (
    cmake -G Ninja -B build -DCMAKE_BUILD_TYPE=Debug
)
call ninja -C build && pushd build && pushd bin && main.exe
cd %CURRENT_DIR%