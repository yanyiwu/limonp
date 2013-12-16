#include "../limonp/Config.hpp"

using namespace Limonp;
bool testConfig()
{
    Config gConfig;
    gConfig.loadFile("testdata/1.conf");
    string res;
    gConfig.get("a", res);
    gConfig.get("cm", res);
    return true;
}

