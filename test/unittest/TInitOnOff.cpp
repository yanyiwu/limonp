#include "InitOnOff.hpp"
#include "gtest/gtest.h"
using namespace Limonp;
class Tmp : public InitOnOff
{
    public:
        Tmp()
        {}
        Tmp(bool flag)
        {
            _setInitFlag(flag);
        }
};
TEST(InitOnOffTest, Test1)
{
    Tmp t;
    ASSERT_FALSE(t);
    Tmp t2(true);
    ASSERT_TRUE(t2);
}
