#include <gtest/gtest.h>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;
TEST(L22, transform_erase_removeif)
{
    string str = "Hi , this is a wORd.";
    string result = "";

    //common way
    for(auto c : str)
    {
        if(isalnum(c))
            result.push_back(tolower(c));
    }

    function<bool(char)> non_letter = [](char c){return not isalnum(c);};
    function<char(char)> to_lower = [](char c){return tolower(c);};

    //using algorithm way
    str.erase(remove_if(str.begin(),
                        str.end(),
                        non_letter), str.end());
    transform(str.begin(), str.end(), str.begin(), to_lower);

    ASSERT_EQ(result, str);
}
