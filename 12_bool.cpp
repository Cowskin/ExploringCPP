#include <gtest/gtest.h>

using namespace std;
TEST(L12,bool_output)
{
 std::cout << "true=" << true << '\n';
  std::cout << "false=" << false << '\n';
  std::cout << std::boolalpha;
  std::cout << "true=" << true << '\n';
  std::cout << "false=" << false << '\n';
}

TEST(L12,bool_assert)
{
  ASSERT_FALSE (false);
  ASSERT_FALSE (0) ;
  ASSERT_FALSE (0.0)    ;
  ASSERT_FALSE(-0.0)    ;
  ASSERT_FALSE('\0')      ;
  ASSERT_TRUE(true);
  ASSERT_TRUE (42) ;
  ASSERT_TRUE (42.4242)  ;
  ASSERT_TRUE (-1)       ;
  ASSERT_TRUE ('\1')      ;
  ASSERT_TRUE ("1")      ;
  ASSERT_TRUE ("false")   ;
  ASSERT_TRUE (std::cout) ;
  ASSERT_TRUE (std::cin)  ;
}

TEST(L12, vector_compare)
{
    ASSERT_TRUE(std::vector<int>({1,2,3,4}) > std::vector<int>({1,2,3}));
    ASSERT_TRUE(std::vector<int>({1,2,3,4}) == std::vector<int>({1,2,3,4}));
    ASSERT_TRUE(std::vector<int>({1,2,3,4}) > std::vector<int>({1,2,3,3}));
}

TEST(L12, string_compare)
{
    ASSERT_TRUE(std::string("1234") > std::string("123"));
    ASSERT_TRUE(std::string("123") == std::string("123"));
    ASSERT_TRUE(std::string("1235") > std::string("1234"));
}

TEST(L12, sort_vector)
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
