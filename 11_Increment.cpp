#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>& reverse_vector(vector<int> &data)
{
    cout << __FUNCTION__ << " Input Data:\n";
    copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, " "));
    cout << endl;

    //Way 1
    for(vector<int>::iterator begin{data.begin()}, end{data.end()};begin != end;)
    {
        if(--end != begin)
        {
            std::iter_swap(begin, end);
            ++begin;
        }
    }

    //Way 2 based on 1
    for(vector<int>::iterator begin{data.begin()}, end{data.end()};begin != end and --end != begin; ++begin)
    {
            std::iter_swap(begin, end);
    }

    //Way 3 based on std algorithm
    reverse(data.begin(),data.end());


    cout << __FUNCTION__ << " Output Data:\n";
    copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, " "));
    cout << endl;

    return data;
}
/*TODO Increment and Decrement run time compare TEST*/
TEST(L11, Vector_Iterator_In_De_crement)
{
    vector<int> data{1,2,3,4};
    ASSERT_EQ(vector<int> ({4,3,2,1}), reverse_vector(data));
    vector<int> data1{1,2,3,4,5};
    ASSERT_EQ(vector<int> ({5,4,3,2,1}), reverse_vector(data1));
    vector<int> data2{1};
    ASSERT_EQ(vector<int> ({1}), reverse_vector(data2));
    vector<int> data3{};
    ASSERT_EQ(vector<int> ({}), reverse_vector(data3));
}
