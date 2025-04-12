cmake_minimum_required(VERSION 3.29.2)

set(CMAKE_CXX_STANDARD 20)

project(main)

#Executable
add_executable(main main.cpp src/jucator.cpp src/pachet.cpp src/septica.cpp)

#Includes directory


#Linked libraries


target_include_directories(main PUBLIC 
                    "${PROJECT_SOURCE_DIR}/include/")