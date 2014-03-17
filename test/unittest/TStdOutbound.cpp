#include "limonp/std_outbound.hpp"
#include "limonp/str_functs.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace Limonp;
TEST(StdOutbound, Test1)
{
    ifstream ifs("../test/testdata/std_outbound.data");
    string s;
    s << ifs;
    string eRes("key1 = val1\n##this is comment\nkey2=val2\n");
    ASSERT_EQ(eRes, s);
}
TEST(StdOutbound, Funct_IsIn)
{
    map<int, int> mp;
    for(size_t i = 1; i < 5; i ++)
    {
        mp[i] = i+1;
    }
    
    ASSERT_TRUE(isIn(mp, 1));
    ASSERT_FALSE(isIn(mp, 0));
}

