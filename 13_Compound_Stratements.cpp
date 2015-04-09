#include <gtest/gtest.h>
using namespace std;
TEST(L13, sort_vector)
{
    vector<int> input({2,4,1,5,3});
    for(vector<int>::iterator iter(input.begin()); iter != input.end();++iter)
    {
        int value(*iter);
        vector<int>::iterator pos = std::lower_bound(input.begin(), input.end(), value);
        input.erase(iter);
        input.insert(pos, value);
    }
    ASSERT_EQ(std::vector<int>({1,2,3,4,5}), input);
}

