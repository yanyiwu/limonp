#include "limonp/logger.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace Limonp;
TEST(LoggerTest, Test1)
{
    ASSERT_TRUE(LogInfo("hehe"));
    ASSERT_TRUE(LogDebug("hehe"));
    ASSERT_TRUE(LogWarn("hehe"));
    ASSERT_TRUE(LogError("hehe"));
    ASSERT_TRUE(LogFatal("hehe"));
}

