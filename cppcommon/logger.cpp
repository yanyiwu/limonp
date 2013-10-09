/************************************
 * file enc : utf8
 * author   : wuyanyi09@gmail.com
************************************/
#include "logger.h"
namespace CPPCOMMON
{
    const char * Logger::_logLevel[LEVEL_ARRAY_SIZE] = {
        "DEBUG","INFO","WARN","ERROR","FATAL"
    };

    const char * Logger::_logFormat = "%s %s:%d %s %s %s\n";
    const char * Logger::_timeFormat = "%Y-%m-%d %H:%M:%S";

    bool Logger::LoggingF(uint level, const char* fileName, int lineNo, const char* functName, const string& fmt, ...)
    {
        int size = 256;
        string msg;
        va_list ap;
        while (1) {
            msg.resize(size);
            va_start(ap, fmt);
            int n = vsnprintf((char *)msg.c_str(), size, fmt.c_str(), ap);
            va_end(ap);
            if (n > -1 && n < size) {
                msg.resize(n);
                break;
            }
            if (n > -1)
              size = n + 1;
            else
              size *= 2;
        }
        return Logging(level, msg, fileName, lineNo, functName);
    }

    bool Logger::Logging(uint level, const char * msg, const char* fileName, int lineNo, const char* functName)
    {
        if(level > LL_FATAL)
        {
            cerr<<"level's value is out of range"<<endl;
            return false;
        }
		char buf[CSTR_BUFFER_SIZE];
		time_t timeNow;
        time(&timeNow);
        size_t ret = strftime(buf, sizeof(buf), _timeFormat, localtime(&timeNow));
        if(0 == ret)
        {
            fprintf(stderr, "stftime failed.\n");
            return false;
        }
        if(level >= LL_WARN)
        {
            fprintf(stderr, _logFormat, buf, fileName, lineNo, functName, _logLevel[level], msg);
        }
        else
        {
            fprintf(stdout, _logFormat, buf, fileName, lineNo, functName, _logLevel[level], msg);
            fflush(stdout);
        }
        return true;
    }
}


#ifdef LOGGER_UT
using namespace CPPCOMMON;
int main()
{
	cout<<__FUNCTION__<<endl;
    LogDebug("debug log!");
    LogInfo("test info log");
    LogWarn("warning log");
    LogInfo("str[%s] int[%d]", "str1");
    LogInfo("str[%s] int[%d]", "str1",15);
    LogError("error log");
    LogFatal("fatal !!!!");
    LogFatal("str[%s] int[%d]", "str1");
    LogFatal("str[%s] int[%d]", "str1", 17,16);
    LogFatal("str");
    return 0;
}
#endif

