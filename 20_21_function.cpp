#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;
void printVector(std::vector<int> const &vec)
{
    //vec[0] = 5;
    for(auto a: vec)
        cout << a;
    cout << endl;
}

void printVector2(const std::vector<int> &vec)
{
    //vec[0] = 5;
    for(auto a: vec)
        cout << a;
    cout << endl;
}
TEST(L20_21, test_const_function)
{
    vector<int> vec{1,2,3,4,5};
    printVector2(vec);
    ASSERT_EQ(vector<int>({1,2,3,4,5}), vec);
}

TEST(L20_21, test_const_pointer)
{
    /*
    int const *p vs const int *p all means the type of p is <int const>
    int * const p; means p is a readonly pointer( address could not change).
    */
    int b = 15;
    int const *a = &b;
    b = 17;
    ASSERT_EQ(*a, 17);

    int *const c = &b;
    b = 19;
    ASSERT_EQ(*c, 19);

    int const * const d = &b;
    b = 15;
    ASSERT_EQ(*d, 15);

    const int *e = &b;
    a = e;
    ASSERT_EQ(*a, *e);

}

TEST(L20_21, test_const_itea)
{
    vector<int> vec{1,2,3,4,5};
    for(vector<int>::const_iterator a {vec.begin()}; a != vec.end(); ++a)
    {
        //do nothing
    }
}

