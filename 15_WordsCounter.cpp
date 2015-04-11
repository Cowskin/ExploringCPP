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
    //find longest word
    //out all result
}
