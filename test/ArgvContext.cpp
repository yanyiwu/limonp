#include <ArgvContext.h>

#ifdef ARGV_FUNCTS_UT

using namespace CPPCOMMON;

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
>>>>>>> e81a664dae9397a6bf937b6dd6482832f67a6cf6
}

#endif
