#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

TEST(L9_0, sort_int)
{
  std::vector<int> data{};
  // Store each integer in the vector.
  data.push_back(2);
  data.push_back(5);
  data.push_back(7);
  data.push_back(1);
  data.push_back(3);

  // Sort the vector.
  std::sort(data.begin(), data.end());

  // Print the vector, one number per line.
  for (std::vector<int>::size_type i{0}, end{data.size()}; i != end; ++i)
    std::cout << data.at(i) << '\n';

  for(auto i: data)
    std::cout << i << '\n';
}

TEST(L9_0, vector_begin_end)
{
    std::vector<std::string> abc;
    ASSERT_EQ(abc.begin(), abc.end());
    ASSERT_EQ(true, abc.empty());
    abc.push_back("test1");
    abc.push_back("test2");
    abc.push_back("test3");
    ASSERT_NE(abc.begin(), abc.end());
}

TEST(L10_0,vector_copy)
{
    std::vector<int> input{ 10, 20, 30 };
    std::vector<int> output{};
    //ASSERT_DEATH(std::copy(input.begin(), input.end(), output.begin()), "");
    /*!!!*/
    output.resize(input.size());
    std::copy(input.begin(), input.end(), output.begin());
    ASSERT_EQ(input, output);
}

TEST(L10_0, __11_1_ )
{
    //TODO "http://skillport.books24x7.com/assetviewer.aspx?bookid=62115&chunkid=492251071&rowid=205&noteMenuToggle=0&leftMenuState=1";
    EXPECT_FALSE(true);
}
