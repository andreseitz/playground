enable_testing()
find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(ExplicitAndImplicitTest
    test_ExplicitAndImplicit.cpp)
target_link_libraries(ExplicitAndImplicitTest GTest::GTest GTest::Main)
gtest_add_tests(TARGET  ExplicitAndImplicitTest)
