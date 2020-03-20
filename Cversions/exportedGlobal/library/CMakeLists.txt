add_library(exp_library
    exp_lib.cpp exp_lib.h)

target_include_directories(exp_library
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )