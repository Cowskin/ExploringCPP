#include <map>
#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

using namespace std;

void read_words_from_file(map<string,int> &word_counter)
{
    ifstream in {"explore15.txt"};
    ASSERT_TRUE(in);

    string word;
    while(in >> word)
        ++word_counter[word];
}

TEST(L15, WordsCounter)
{
    map<string,int> words_counter;
    read_words_from_file(words_counter);
    string::size_type longest_size{0};
    //find longest word
    for(map<string, int>::iterator iter {words_counter.begin()}; iter != words_counter.end(); ++iter)
        if(longest_size < iter->first.size())
            longest_size = iter->first.size();

    cout << "longest_size is:" << longest_size <<endl;
    //out all result
    for(map<string, int>::iterator iter {words_counter.begin()}; iter != words_counter.end(); ++iter)
    {
        cout << setw(longest_size + 5) << left << iter->first << right << iter->second << endl;
    }
}

TEST(L15, Words_Search)
{
    map<string,int> words_counter;
    read_words_from_file(words_counter);
    map<string, int>::iterator result = words_counter.find("the");
    ASSERT_NE(result, words_counter.end());
    ASSERT_EQ(words_counter.find("thewordnotexist"),words_counter.end());
    cout << "the word \"the\" is in the document, count:" << result->second << endl;
}

TEST(L15, Map_iter_Pair)
{
    map<string,int> words_counter;
    ASSERT_EQ((map<string,int>::size_type(0)), words_counter.size());
    words_counter["123"];
    words_counter["abc"];
    ASSERT_EQ((map<string,int>::size_type(2)), words_counter.size());
    words_counter["ttt"] = 5;

    for(map<string, int>::iterator iter {words_counter.begin()}; iter != words_counter.end(); ++iter)
    {
        std::pair<string, int> data = *iter;
        /* 2 ways to access map iter (pair) */
        ASSERT_EQ(data.first, (*iter).first);
        ASSERT_EQ(data.first, iter->first);
    }
}
