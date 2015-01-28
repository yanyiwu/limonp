#include "gtest/gtest.h"
#include "Colors.hpp"
#include "Logger.hpp"

using namespace Limonp;

TEST(ColorPrint, Test1) {
  ColorPrintln(RED, "hello %s", "world");
  ColorPrintln(RED, "hello %s", "world");
  LogInfo("hello world");
  ColorPrintln(RED, "hello %s", "world");
  ColorPrintln(GREEN, "hello %s", "world");
  LogInfo("hello world");
  ColorPrintln(BLACK, "hello %s", "world");
  ColorPrintln(YELLOW, "hello %s", "world");
  ColorPrintln(BLUE, "hello %s", "world");
  ColorPrintln(PURPLE, "hello %s", "world");
  ColorPrintln(PURPLE, "hello %s", "world", " and colors");
}

