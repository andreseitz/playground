#include "gtest/gtest.h"

class FixedSizeArray : public ::testing::Test
{

protected:
    char str[5] = {'H','e', 'l', 'l', 'o'};

    void checkArrayPassedAsArray(char arr[])
    {
        EXPECT_EQ(str, arr);
        EXPECT_EQ(str, &arr[0]);
        EXPECT_EQ(sizeof(char*), sizeof(arr));
        EXPECT_EQ(sizeof(char*), sizeof(&arr[0]));
    }

    void checkArrayPassedAsPointer(char* arr)
    {
        EXPECT_EQ(str, arr);
        EXPECT_EQ(str, &arr[0]);
        EXPECT_EQ(sizeof(char*), sizeof(arr));
        EXPECT_EQ(sizeof(char*), sizeof(&arr[0]));
    }

};

TEST_F(FixedSizeArray, firstElementPointerEquals)
{
    EXPECT_EQ(&str[0], str);
}

TEST_F(FixedSizeArray, holdsSizeInBytes)
{
    EXPECT_EQ(5 * sizeof(char), sizeof(str));
}

TEST_F(FixedSizeArray, isDecayingToPointerWhenPassedToFunctionAsArray)
{
    checkArrayPassedAsArray(str);
}

TEST_F(FixedSizeArray, isDecayingToPointerWhenPassedToFunctionAsPointer)
{
    checkArrayPassedAsPointer(str);
}

class PassToFunction : public ::testing::Test
{
protected:
void checkWithArray(char arr[], int length)
{
    EXPECT_EQ(sizeof(char*), sizeof(arr));
}

void checkWithConstArray(const char arr[], int length)
{
    EXPECT_EQ(sizeof(char*), sizeof(arr));
}

void modifyArray(char array[])
{
    array[2] = 'L';
}

void modifyPointer(char* pointer)
{
    pointer[2] = 'L';
}

};

TEST_F(PassToFunction, asArrayDecaysToPointer)
{
    char array[] = "Hello";
    checkWithArray(array, 5);
}

TEST_F(PassToFunction, asConstArrayDecaysToPointer)
{
    const char array[] = "Hello";
    checkWithConstArray(array, 5);
}

TEST_F(PassToFunction, modificationOfArray)
{
    char array[] = "Hello";
    modifyArray(array);

    EXPECT_STREQ("HeLlo", array);
}

TEST_F(PassToFunction, modificationOfPointerToStringLiteralFails)
{
    char * array = "Hello";
    ASSERT_DEATH(modifyArray(array),"");

    //EXPECT_STREQ("HeLlo", array);
}

TEST_F(PassToFunction, modificationOfPointerToArray)
{
    char array[] = "Hello";
    char * pointer = array;
    modifyArray(array);
    
    EXPECT_STREQ("HeLlo", array);
}