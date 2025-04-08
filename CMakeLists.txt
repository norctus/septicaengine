cmake_minimum_required(VERSION 3.29.2)

set(CMAKE_CXX_STANDARD 20)

project(main)

#Executable
add_executable(main main.cpp)

#Includes directory
add_subdirectory(include)

#Linked libraries
target_link_libraries(main ws2_32)

target_include_directories(main PUBLIC 
                    "${PROJECT_SOURCE_DIR}/include/")