PROJECT(LIMONP)

cmake_minimum_required(VERSION 2.6)

ADD_DEFINITIONS(-O3 -Wall -g)
IF(APPLE) # mac os
    ADD_DEFINITIONS(-std=c++0x)
endif()
ADD_SUBDIRECTORY(test)

ENABLE_TESTING()
ADD_TEST(NAME testrun COMMAND test.run)
