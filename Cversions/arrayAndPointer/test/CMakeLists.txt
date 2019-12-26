enable_testing()
find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(ArrayAndPointerTest 
    test_ArrayAndPointer.cpp
    test_Strtok.cpp)
target_link_libraries(ArrayAndPointerTest GTest::GTest GTest::Main)
gtest_add_tests(TARGET  ArrayAndPointerTest)