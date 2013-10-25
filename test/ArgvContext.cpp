#include <ArgvContext.hpp>

using namespace Limonp;

int main(int argc, char** argv)
{
    //map<string,string> argvMap;
    //getArgvMap(argc, argv, argvMap);
    //PRINT_MAPSS(argvMap);
    ArgvContext arg(argc, argv);
    cout<<arg.toString()<<endl;
    cout<<arg[1]<<endl;
    cout<<arg["--hehe"]<<endl;
    cout<<pairToString<int,double>(pair<int, double>(1,1.2))<<endl;
    cout<<arg.hasKey("-help")<<endl;
    return 0;
}

