#include "../limonp/ArgvContext.hpp"

using namespace Limonp;

bool testArgvContext()
{
    //map<string,string> argvMap;
    //getArgvMap(argc, argv, argvMap);
    //PRINT_MAPSS(argvMap);
    ArgvContext arg(argc, argv);
    cout<<arg<<endl;
    cout<<arg[1]<<endl;
    cout<<arg["--hehe"]<<endl;
    //cout<<pairToString<int,double>(pair<int, double>(1,1.2))<<endl;
    cout<<arg.hasKey("-help")<<endl;
    string s;
    s<<arg;
    cout<<s;
    return true;
}

