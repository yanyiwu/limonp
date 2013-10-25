/************************************
 * file enc : utf8
 * author   : wuyanyi09@gmail.com
************************************/
#include <logger.hpp>

using namespace Limon;
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
