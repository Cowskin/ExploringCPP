#include <gtest/gtest.h>
#include <strstream>
#include <iostream>

using namespace std;
TEST(L17, basic_eq_4_char)
{
    ASSERT_EQ('7', '0' + 7);
    ASSERT_EQ('7', '7' + '\0');
}

TEST(L17, io_1)
{
    char c = 0;
    stringstream str_stream {"Your heart is full of fertile seeds, waiting to sprout."};
    stringstream result1, result2;
    while(str_stream >> c)
        result1 << c;

    /*
    When you finish reading all the contents of your file, the state of the stream would be eof, thus all subsequent input operations will fail.
    Then we need call clear function:http://www.cplusplus.com/reference/ios/ios/clear/
    */
    str_stream.clear();
    str_stream.seekg(0, str_stream.beg);

    str_stream >> noskipws;
    while(str_stream >> c)
        result2 << c;

    cout << "result1 with default behavior skip ws: " << result1.rdbuf() << endl;
    cout << "result2 with do str_stream >> noskipws: " << result2.rdbuf() << endl;
    ASSERT_STRNE(result1.str().c_str(), result2.str().c_str());

}
