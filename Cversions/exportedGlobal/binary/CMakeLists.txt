add_executable(exp_binary
    main.cpp 
    exp_bin.cpp exp_bin.h)

target_link_libraries(exp_binary PUBLIC exp_library)

target_include_directories(exp_binary PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          )