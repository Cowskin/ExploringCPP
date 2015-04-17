#include <gtest/gtest.h>
#include <locale>
#include <iostream>

TEST(L19, is_upper_lower)
{
    ASSERT_TRUE(std::isupper('A'));
    ASSERT_FALSE(std::isupper('a'));

    ASSERT_TRUE(std::isupper('A', std::locale("")));
    ASSERT_FALSE(std::isupper('a', std::locale("")));

    ASSERT_TRUE(std::islower('a'));
    ASSERT_FALSE(std::islower('*'));
    ASSERT_FALSE(std::isupper('*'));
}

TEST(L19, to_upper_lower)
{
    ASSERT_EQ('D', std::toupper('d'));
    ASSERT_EQ('d', std::tolower('D'));

    ASSERT_EQ('D', std::toupper('d', std::locale("")));
    ASSERT_EQ('d', std::tolower('D', std::locale("")));
}
