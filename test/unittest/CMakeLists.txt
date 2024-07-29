SET(GTEST_ROOT_DIR ${PROJECT_SOURCE_DIR}/test/gtest)

INCLUDE_DIRECTORIES(${GTEST_ROOT_DIR} ${GTEST_ROOT_DIR}/include ${PROJECT_SOURCE_DIR}/include)

ADD_EXECUTABLE(test.run 
	gtest_main.cpp 
	TLogging.cpp  
	TArgvContext.cpp  
	TConfig.cpp
	TStringUtil.cpp 
	TStdExtension.cpp 
	TLocalVector.cpp 
	TClosure.cpp 
	TColorPrint.cpp
	#TMd5.cpp
	#TFileLock.cpp
	#TBoundedQueue.cpp 
	#TMutexLock.cpp 
	#TBlockingQueue.cpp 
	#TThread.cpp 
	#TThreadPool.cpp 
)
find_package(Threads REQUIRED)
TARGET_LINK_LIBRARIES(test.run gtest Threads::Threads)
