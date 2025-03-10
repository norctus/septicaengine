cmake_minimum_required(VERSION 3.29.2)

set(CMAKE_CXX_STANDARD 20)

project(main)
add_executable(main main.cpp)
add_subdirectory(include)
target_link_libraries(main INTERFACE IncludeFiles)

target_include_directories(main PUBLIC 
                    "${PROJECT_SOURCE_DIR}/include/")