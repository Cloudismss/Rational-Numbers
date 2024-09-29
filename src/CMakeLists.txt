set(Sources
        # Sources
        "rational.cpp"
        "test_rational.cpp"
)

set(Dirs
        "../include"
)

add_library(src ${Sources})
target_include_directories(src PUBLIC ${Dirs})