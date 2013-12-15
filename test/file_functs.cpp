#include "../limonp/io_functs.hpp"
#include <iostream>
using namespace Limonp;
bool testFileFuncts()
{
    char filename[] = "1/2/3";
    if(!checkFileExist(filename))
    {
        createDir(filename);
    }
    return true;
}
