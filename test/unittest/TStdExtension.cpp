#include "StdExtension.hpp"
#include "StringUtil.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace Limonp;
TEST(StdOutbound, Test1)
{
    ifstream ifs("../test/testdata/StdExtension.data");
    string s;
    s << ifs;
    ASSERT_EQ("key1 = val1\n##this is comment\nkey2=val2\n", s);

    const char * outFileName = "stdoutbuond.test.tmp";
    ofstream ofs(outFileName);
    s = outFileName;
    ofs << s;
    ASSERT_TRUE(ofs);
    ofs.close();

    ifstream ifs2(outFileName);
    s << ifs2;
    ASSERT_EQ(outFileName, s);
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

TEST(StdOutbound, Test2)
{
    map<int, int> mp1;
    mp1[1] = 2;
    mp1[2] = 3;
    string s;
    ASSERT_EQ(s << mp1, "{1:2, 2:3}");
    unordered_map<int,int> mp2;
    mp2[1] = 2;
    mp2[2] = 3;
    ASSERT_EQ(s << mp2, "{1:2, 2:3}");
}
