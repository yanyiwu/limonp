#include "limonp/ArgvContext.hpp"
#include "gtest/gtest.h"

using namespace Limonp;

TEST(ArgvContextTest, Test1)
{
    const char * argv[] = {"./exe1", "--hehe", "11", "key2", "-k", "val"};
    ArgvContext arg(sizeof(argv)/sizeof(argv[0]), argv);
    cout<<arg<<endl;
    cout<<arg[1]<<endl;
    cout<<arg["--hehe"]<<endl;
    cout<<arg.hasKey("-help")<<endl;
    string s;
    s<<arg;
    cout<<s;
}

