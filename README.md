# Septica Engine
An attempt on developing my so far learned skills through creating all kinds of cards games.

# Structure
    Source code in src, headers in include. Also there is the **assets** folder which contains all
the necessary assets for SFML graphics, such as fonts, sprites and others.

# Build the project
    The project is made using CMake and it's currently **supported only for windows**.

    To build the project you just have to run buildAndRun.bat. The first compilation will take some
time because it's installing the needed libraries, mainly SFML.
    Alternatively, if you want to manually build and run, you can give the following commands in console:
    ```
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```
    The executable will be in `./build/bin/Debug` as main.exe.

# Dependencies
    This project uses [SFML](https://github.com/SFML/SFML.git) for graphics interface and 
[Wired](https://github.com/Robertkq/Wired.git) for networking! It's currently in early stage
of development.
