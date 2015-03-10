#include <iostream>
#include <gtest\gtest.h>
using namespace std;
using namespace testing;

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    cout << "Exploring CPP 11" << endl;
    return RUN_ALL_TESTS();
}
