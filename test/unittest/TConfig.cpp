#include "limonp/Config.hpp"
#include "gtest/gtest.h"

using namespace Limonp;
TEST(COnfigTest, Test1)
{
    Config gConfig("../test/testdata/1.conf");
    string res;
    res << gConfig;
    print(res);
    gConfig.get("key1", res);
    gConfig.get("key2", res);
}

