SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/test)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/test/lib)

SET(GTEST_ROOT_DIR gtest-1.6.0)

INCLUDE_DIRECTORIES(${GTEST_ROOT_DIR} ${GTEST_ROOT_DIR}/include ${PROJECT_SOURCE_DIR}/src)
ADD_LIBRARY(gtest STATIC ${GTEST_ROOT_DIR}/src/gtest-all.cc)
ADD_EXECUTABLE(test.run gtest_main.cpp TCastFloat.cpp  TInitOnOff.cpp TLogger.cpp  TArgvContext.cpp  TConfig.cpp TMd5.cpp TStringUtil.cpp TStdExtension.cpp TMutexLock.cpp TBlockingQueue.cpp TBoundedQueue.cpp TCodeConverter.cpp)
TARGET_LINK_LIBRARIES(gtest pthread)
TARGET_LINK_LIBRARIES(test.run gtest pthread)

