#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;



void fill_IndStrMap(std::map<int, std::string> &data)
{
  data[1] = "1.please keep a low profile." ;
  data[2] = "2.I would like a refill." ;
  data[3] = "3.I can't feel my legs." ;
  data[4] = "4.I am going to distract her." ;
  data[5] = "5.They are all wellreceived." ;
  data[6] = "6.I have to organize my thoughts." ;
  data[7] = "7.The little boy is bouncy.";
  data[8] = "8.I admire your candor.";
  data[9] = "9.My ear is ringing.";
  data[10] = "10.She has a natural charisma.";
}

typedef std::map<int, std::string> IndStrMap;
typedef std::map<int, std::string>::iterator IndStrMap_Iter;
IndStrMap data1;

TEST(L16, test_typedef)
{
  fill_IndStrMap(data1);
  for(IndStrMap_Iter iter{data1.begin()}; iter != data1.end(); ++iter )
  {
    cout << setw(4) << left << iter->first ;
    cout << iter->second << endl;

  }
}

using U_IndStrMap = std::map<int, std::string> ;
using U_IndStrMap_Iter =  std::map<int, std::string>::iterator ;
U_IndStrMap data2;
TEST(L16, test_alias_using)
{
  fill_IndStrMap(data2);
  ASSERT_EQ(data1, data2);
}
