PROJECT(limonp)

cmake_minimum_required(VERSION 2.6)

ADD_DEFINITIONS(-O3 -Wall -g)
IF(APPLE) # mac os
    ADD_DEFINITIONS(-std=c++0x)
endif()
ADD_SUBDIRECTORY(test)

ENABLE_TESTING()
ADD_TEST(NAME ./test/test.run COMMAND ./test/test.run)
ADD_TEST(NAME ./test/demo COMMAND ./test/demo)
ADD_TEST(NAME ./test/thread_pool_demo COMMAND ./test/thread_pool_demo)
