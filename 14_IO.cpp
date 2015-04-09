#include <gtest/gtest.h>
#include <iostream>
#include <fstream>

using namespace std;
TEST(L14, io)
{
    const string filename = "list1402.out";

    std::ifstream in {"nullfile.txt"};
    ASSERT_FALSE(in);
    std::perror("nullfile.txt");

    std::ofstream out{filename};
    ASSERT_TRUE(out);

    for(int i=0;i<10;i++)
        out << i <<" ";

    ASSERT_EQ(20, out.tellp());
    out.close();

    /*file size calculate 1*/
    in.open(filename);
    auto begin = in.tellg();
    in.seekg(0, ios_base::end);
    ASSERT_EQ(20, in.tellg() - begin);
    in.close();

    /*file size calculate 1*/
    in.open(filename, ios::binary | ios::ate);
    ASSERT_EQ(20, in.tellg());
    in.close();

    /*read file test*/
    string in_str{""};
    string x{};
    in.open(filename);
    while (in >> x)
    {
        in_str.append(x);
    }
    ASSERT_STREQ("0123456789", in_str.c_str());
    /*remove file test */
    in.open(filename);
    ASSERT_TRUE(in.is_open());
    in.close();
    ASSERT_TRUE(std::ifstream{filename});
    remove(filename.c_str());
    ASSERT_FALSE(std::ifstream{filename});

}
