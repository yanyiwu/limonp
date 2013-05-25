#include "logger.h"
namespace CPPCOMMON
{
	const char * Logger::_logFormat =  "%s:%d [%s]:%s";
	Logger::Logger()
	{
		_isCoutOpen = true;
		_logLevel[LL_DEBUG] = "DEBUG";
		_logLevel[LL_INFO] = "INFO";
		_logLevel[LL_WARN] = "WARN";
		_logLevel[LL_ERROR] = "ERROR";
		_logLevel[LL_FATAL] = "FATAL";
		InitDefault();
	}
	Logger::~Logger()
	{
		if(_logFile)
		{
			_logFile.close();
		}
	}
	//Logger::AddHandler
	void Logger::InitDefault()
	{
		string logDir = "./log/";
		string logName = "run.log";
		if(!checkDirExist(logDir.c_str()))
		{
			createDir(logDir.c_str());
		}
		
		_logFile.open((logDir + logName).c_str(), ios::app);
		
	}
	bool Logger::Logging(unsigned int level, const string& msg, const string& fileName, const int& lineNo)
	{
		if(level < LL_DEBUG || level > LL_FATAL)
		{
			cerr<<"level's value is out of range"<<endl;
			return false;
		}
		sprintf(_cStrBuf, _logFormat, fileName.c_str(), lineNo, _logLevel[level], msg.c_str());
		if(_isCoutOpen)
		{
		  cout<<_cStrBuf<<endl;
		}
		if(_logFile)
		{
			_logFile<<_cStrBuf<<endl;
		}
		return true;
	}
}
namespace CPPCOMMON
{
	Logger loggerSingleTon;
}


#ifdef UNIT_TEST
using namespace CPPCOMMON;
int main()
{
	/*
	ofstream fout;
	fout.open("tmp.log", ios::app);
	fout<<"11111"<<endl;
	fout.close();
	f2<<"222"<<endl;
	*/
	//loggerSingleTon.Logging(LL_INFO, "test", __FILE__, __LINE__);
	LogInfo("test info log");
	return 0;
}
#endif

