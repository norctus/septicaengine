add_library(SepticaGame
    carte.cpp
    jucator.cpp
    pachet.cpp
    septica.cpp
)

target_include_directories(SepticaGame PUBLIC
    "${PROJECT_SOURCE_DIR}/include/SepticaGame"
)

target_link_libraries(SepticaGame PUBLIC
    sfml-graphics sfml-window sfml-system
)

# target_compile_definitions(DDGEngine PRIVATE MY_DEBUG)