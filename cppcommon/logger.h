#ifndef CPPCOMMON_LOGGER_H
#define CPPCOMMON_LOGGER_H

#define LOG_DEBUG 1
#define LOG_INFO 2
#define LOG_WARN 3
#define LOG_ERROR 4
#define LOG_FATAL 5
#define LEVEL_ARRAY_SIZE 6
#define CSTR_BUFFER_SIZE 1024

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
namespace CPPCOMMON
{
	using namespace std;
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
	};
}

#endif
