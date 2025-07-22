add_library(DDGEngine
    MainMenu.cpp
    Options.cpp
)

target_include_directories(DDGEngine PUBLIC
    "${PROJECT_SOURCE_DIR}/include/DDGEngine"
)

target_link_libraries(DDGEngine PUBLIC
    sfml-graphics sfml-window sfml-system
)