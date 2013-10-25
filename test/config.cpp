#include <config.hpp>

using namespace Limonp;
int main()
{
    Config gConfig;
    gConfig.init("1.conf");
    gConfig.init("1.conf");
    gConfig.display();
    string res;
    gConfig.get("a", res);
    gConfig.get("cm", res);
    return 0;
}

