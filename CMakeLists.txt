cmake_minimum_required(VERSION 3.29.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(main)

#Executable
add_executable(main src/carte.cpp src/main.cpp src/jucator.cpp src/pachet.cpp src/septica.cpp)

#Includes directory

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(sfml)

#Linked libraries
target_link_libraries(main 
    PRIVATE 
        sfml-graphics
        sfml-window
        sfml-system
        )

target_include_directories(main PUBLIC 
                    "${PROJECT_SOURCE_DIR}/include/")