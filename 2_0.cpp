/// Read the program and determine what the program does.

#include <iostream>
#include <limits>
#include <gtest\gtest.h>
#include <cmath>

TEST(L2_0, limits_lib)
{
    std::cout << "min int = " << std::numeric_limits<int>::min() << "\nmax int= " << std::numeric_limits<int>::max() << '\n';
    ASSERT_EQ((int)pow(2,32), std::numeric_limits<int>::max());
    ASSERT_EQ(1, std::numeric_limits<bool>::max());
 }


