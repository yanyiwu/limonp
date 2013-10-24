#include <config.h>

using namespace CPPCOMMON;
int main()
{
    Config gConfig;
    gConfig.init("1.conf");
    gConfig.init("1.conf");
    gConfig.display();
    cout<<gConfig.get("a")<<endl;
    cout<<gConfig.get("cm")<<endl;
    return 0;
}

