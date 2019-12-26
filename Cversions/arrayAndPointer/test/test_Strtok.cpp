#include "gtest/gtest.h"
#include <typeinfo>
#include <iostream>


#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

template <class T>
std::string
type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
#else
                nullptr,
#endif
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}





class StringTokenize : public ::testing::Test
{

protected:

    void validate_strtok(char* token, char* input, char* delim)
    {
        EXPECT_EQ(&input[0], &token[0]);

        EXPECT_EQ(input[0], token[0]);
        EXPECT_EQ('H', input[0]);
        EXPECT_EQ(input[1], token[1]);
        EXPECT_EQ('e', input[1]);
        EXPECT_EQ(input[2], token[2]);
        EXPECT_EQ(0, input[2]);

        token = strtok(NULL, delim);
        EXPECT_EQ(input[4], token[0]);
        EXPECT_EQ('o', input[4]);
        EXPECT_EQ(input[5], token[1]);
        EXPECT_EQ(0, token[1]);

        token = strtok(NULL, delim);
        EXPECT_EQ(nullptr, token);
    }
};

TEST_F(StringTokenize, getCorrectSubstringWhenFixedSizeArrayIsInput)
{
    char str[6] = {'H','e', 'l', 'l', 'o', 0};

    char* result = strtok(str, "l");
    validate_strtok(result, str, "l");
}

TEST_F(StringTokenize, getCorrectSubstringWhenCharArrayIsInput)
{
    char str[] = "Hello";
    char* result = strtok(str, "l");
    validate_strtok(result, str, "l");
}

TEST_F(StringTokenize, getCorrectSubstringWhenPointerToFirstElementOfCharArrayIsInput)
{
    char str[] = "Hello";
    char* ptr = &str[0];
    char* result = strtok(ptr, "l");
    validate_strtok(result, str, "l");
}

TEST_F(StringTokenize, getCorrectSubstringWhenPointerToCharArrayIsInput)
{
    char str[] = "Hello";
    char* ptr = str;
    char* result = strtok(ptr, "l");
    validate_strtok(result, str, "l");
}


TEST_F(StringTokenize, crashesWhenPointerToStringLiteralIsInput)
{
    char* ptr = "Hello";
    ASSERT_DEATH(strtok(ptr, "l"), "");
}

TEST_F(StringTokenize, crashesWhenStringLiteralIsInput)
{
    ASSERT_DEATH(strtok("Hello", "l"), "");
}
