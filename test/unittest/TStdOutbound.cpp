#include "limonp/std_outbound.hpp"
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

