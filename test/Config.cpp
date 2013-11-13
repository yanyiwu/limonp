#include <Config.hpp>

using namespace Limonp;
int main()
{
    Config gConfig;
    gConfig.loadFile("testdata/1.conf");
    string res;
    gConfig.get("a", res);
    gConfig.get("cm", res);
    return 0;
}

