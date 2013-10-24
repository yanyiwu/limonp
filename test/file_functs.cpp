/************************************
 * file enc : utf8
 * author   : wuyanyi09@gmail.com
************************************/
#include <file_functs.h>

#include <iostream>
using namespace CPPCOMMON;
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
