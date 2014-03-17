#define LOGGER_LEVEL LL_INFO
#include "limonp/logger.hpp"
#include "gtest/gtest.h"
using namespace Limonp;
#define LOGGER_LEVEL LL_INFO
#define LOGGER_LEVEL LL_INFO
#define LOGGER_LEVEL LL_INFO
TEST(LoggerTest, Test1)
{
    LogInfo("hehe");
    LogDebug("hehe");
    LogWarn("hehe");
    LogError("hehe");
    LogFatal("hehe");
    LogInfo("str[%s] int[%d]", "str1",15);
}

TEST(LoggerTest, Test2)
{
    LogInfo("hehe");
    LogDebug("hehe");
    LogWarn("hehe");
    LogError("hehe");
    LogFatal("hehe");
    LogInfo("str[%s] int[%d]", "str1",15);
}
