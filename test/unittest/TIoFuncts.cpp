#include "limonp/io_functs.hpp"
#include "gtest/gtest.h"
#include <iostream>
using namespace Limonp;
TEST(IoFunctsTest, Test1)
{
    string s;
    loadFile2Str("../test/testdata/io_testfile", s);
    EXPECT_EQ("line1\nline2\n", s);
}

