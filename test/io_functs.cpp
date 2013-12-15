#include "../limonp/io_functs.hpp"

#include <iostream>
using namespace Limonp;
bool testIoFuncts()
{
    cout<<loadFile2Str("testfile")<<endl;
    return true;
}
