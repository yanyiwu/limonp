/************************************
 * file enc : utf8
 * author   : wuyanyi09@gmail.com
************************************/
#include <io_functs.hpp>

#include <iostream>
using namespace Limon;
using namespace std;
int main()
{
    char filename[] = "1/2/3";
    if(!checkFileExist(filename))
    {
        createDir(filename);
    }
    return 0;
}
