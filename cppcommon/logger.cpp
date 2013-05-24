#include "logger.h"
namespace CPPCOMMON
{
	Logger::Logger()
	{
	}
	Logger::~Logger()
	{
	}
	//Logger::AddHandler
}


#ifdef UNIT_TEST
using namespace CPPCOMMON;
int main()
{
	fstream fout;
	fout.open("tmp.log", ios::out|ios::app);
	fout<<"11111"<<endl;
	fout.close();
	Logger logger;
	return 0;
}
#endif

