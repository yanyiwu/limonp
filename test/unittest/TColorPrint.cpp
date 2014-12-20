#include "gtest/gtest.h"
#include "ColorPrint.hpp"

using namespace Limonp;

TEST(ColorPrint, Test1)
{
    ColorPrint("hello colors\n");
    ColorPrint("hello colors\n", BLACK);
    ColorPrint("hello colors\n", RED);
    ColorPrint("hello colors\n", GREEN);
    ColorPrint("hello colors\n", YELLOW);
    ColorPrint("hello colors\n", BLUE);
    ColorPrint("hello colors\n", PURPLE);
}

