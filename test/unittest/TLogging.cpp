#define LOGGING_LEVEL WARNING
#include "limonp/Logging.hpp"
#include "gtest/gtest.h"

TEST(Logging, Test1) {
  LOG(DEBUG) << "xxx" << " yyy";
  LOG(INFO) << "hello";
  LOG(WARNING) << "hello";
  LOG(ERROR) << "hello";
  //CHECK(false) << "hello, " << "world";
  //LOG(FATAL) << "hello";
}
