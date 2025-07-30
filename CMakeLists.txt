cmake_minimum_required(VERSION 3.29.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(main)

#Executable
add_executable(main src/main.cpp)

#Includes directory
add_subdirectory(src/DDGEngine)
add_subdirectory(src/SepticaGame)

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
        DDGEngine
        SepticaGame
        )

target_include_directories(main PUBLIC 
                    "${PROJECT_SOURCE_DIR}/include")

target_compile_definitions(main PRIVATE MY_DEBUG)