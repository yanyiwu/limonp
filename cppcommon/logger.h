#ifndef CPPCOMMON_LOGGER_H
#define CPPCOMMON_LOGGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "file_functs.h"

#define LL_DEBUG 1
#define LL_INFO 2
#define LL_WARN 3
#define LL_ERROR 4
#define LL_FATAL 5
#define LEVEL_ARRAY_SIZE 6
#define CSTR_BUFFER_SIZE 1024


#define LogDebug(msg) loggerSingleTon.Logging(LL_DEBUG, msg, __FILE__, __LINE__)
#define LogInfo(msg) loggerSingleTon.Logging(LL_INFO, msg, __FILE__, __LINE__)
#define LogWarn(msg) loggerSingleTon.Logging(LL_WARN, msg, __FILE__, __LINE__)
#define LogError(msg) loggerSingleTon.Logging(LL_ERROR, msg, __FILE__, __LINE__)
#define LogFatal(msg) loggerSingleTon.Logging(LL_FATAL, msg, __FILE__, __LINE__)



namespace CPPCOMMON
{
	using namespace std
	class Logger
	{
		public:
			Logger();
			~Logger();
		public:
			void InitDefault();
			bool Logging(unsigned int level, const string& msg, const string& fileName, const int& lineNo);
		private:
			bool _isCoutOpen;
			char _cStrBuf[CSTR_BUFFER_SIZE];
			const char * _logLevel[LEVEL_ARRAY_SIZE];
			ofstream _logFile;
			static const char * _logFormat;
	};
}

namespace CPPCOMMON
{
	extern Logger loggerSingleTon;
}

#endif
