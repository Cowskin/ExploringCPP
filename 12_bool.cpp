#include <gtest/gtest.h>

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
