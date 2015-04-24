#include <gtest/gtest.h>
#include <map>
#include <string>
#include <fstream>
using namespace std;

TEST(L17, Character_Categories_Read)
{
    map<string, int> word_counter;
    ifstream in {"explore15.txt"};
    ASSERT_TRUE(in);

    locale native("");
    in.imbue(native);
    cout.imbue(native);

    string word;

    while(in >> word)
    {
        string copy{};
        for(auto a: word)
        {
            if(std::isalnum(a, locale("")))
                copy.push_back(a);
        }
        if(not copy.empty())
            ++word_counter[copy];
    }

    for(auto wd_pair : word_counter)
    {
        //cout << wd_pair.first << '\t' << wd_pair.second << endl;
    }
    cout << "the number of words in for explore15.txt is :" <<  word_counter.size() << endl;
}
