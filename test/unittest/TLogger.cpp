#define LOGGER_LEVEL LL_INFO
#include "limonp/logger.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace Limonp;
#define LOGGER_LEVEL LL_INFO
#define LOGGER_LEVEL LL_INFO
#define LOGGER_LEVEL LL_INFO
TEST(LoggerTest, Test1)
{
    ASSERT_TRUE(LogInfo("hehe"));
    ASSERT_TRUE(LogDebug("hehe"));
    ASSERT_TRUE(LogWarn("hehe"));
    ASSERT_TRUE(LogError("hehe"));
    ASSERT_TRUE(LogFatal("hehe"));
    ASSERT_TRUE(LogInfo("str[%s] int[%d]", "str1",15));
}

TEST(LoggerTest, Test2)
{
    ASSERT_TRUE(LogInfo("hehe"));
    ASSERT_TRUE(LogDebug("hehe"));
    ASSERT_TRUE(LogWarn("hehe"));
    ASSERT_TRUE(LogError("hehe"));
    ASSERT_TRUE(LogFatal("hehe"));
    ASSERT_TRUE(LogInfo("str[%s] int[%d]", "str1",15));
}
