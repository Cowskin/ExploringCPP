#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

TEST(L9_L10_0, int_vector_sort_then_loop_output)
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
  std::cout << "Demo vector size_type :" << '\n';
  for (std::vector<int>::size_type i{0}, end{data.size()}; i != end; ++i)
    std::cout << data.at(i) << ' ';
  std::cout << '\n';

  std::cout << "Demo vector iterator:" << '\n';
  for(std::vector<int>::iterator  i{data.begin()}, end{data.end()};i != end; ++i)
    std::cout<< *i<< ' ';
  std::cout << '\n';

  std::cout << "Demo vector auto (range-based for loop/for-each loop):" << '\n';
  std::cout << "--better than iterator traverse  (the loop define a hidden iterator, calling its begin() and end()) " << '\n';
  for(auto i: data)
    std::cout << i << ' ';
  std::cout << '\n';

  for(int i: data)
    std::cout << i << ' ';
  std::cout << '\n';
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
