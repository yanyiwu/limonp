#include "limonp/Config.hpp"
#include "gtest/gtest.h"

using namespace Limonp;
TEST(COnfigTest, Test1)
{
    Config gConfig("../test/testdata/1.conf");
    string res;
    ASSERT_EQ("{key1:val1, key2:val2}", res << gConfig);
    gConfig.get("key1", res);
    ASSERT_EQ("val1", res);
    gConfig.get("key2", res);
    ASSERT_EQ("val2", res);
}

