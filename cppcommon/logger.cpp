#include "logger.h"
namespace CPPCOMMON
{
	Logger::Logger()
	{
		_isCoutOpen = true;
		_logLevel[LOG_DEBUG] = "DEBUG";
		_logLevel[LOG_INFO] = "INFO";
		_logLevel[LOG_WARN] = "WARN";
		_logLevel[LOG_ERROR] = "ERROR";
		_logLevel[LOG_FATAL] = "FATAL";
	}
	Logger::~Logger()
	{
	}
	//Logger::AddHandler
	void Logger::InitDefault()
	{
	}
	bool Logger::Logging(unsigned int level, const string& msg, const string& fileName, const int& lineNo)
	{
		if(level < LOG_DEBUG || level > LOG_FATAL)
		{
			cerr<<"level's value is out of range"<<endl;
			return false;
		}
		string format = "%s:%d [%s]:%s";
		sprintf(_cStrBuf, format.c_str(), fileName.c_str(), lineNo, _logLevel[level], msg.c_str());
		if(_isCoutOpen)
		  cout<<_cStrBuf<<endl;
		return true;
	}
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
	Logger logger;
	logger.Logging(LOG_INFO, "test", __FILE__, __LINE__);
	return 0;
}
#endif

