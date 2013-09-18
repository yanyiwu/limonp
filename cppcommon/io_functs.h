/************************************
 * file enc : utf8
 * author   : wuyanyi09@gmail.com
************************************/
#ifndef CPPCOMMON_IO_FUNCTS_H
#define CPPCOMMON_IO_FUNCTS_H
#include <fstream>
#include <iostream>
namespace CPPCOMMON
{
    using namespace std;
    string loadFile2Str(const char * const filepath);
    void loadStr2File(const char * const filename, ios_base::openmode mode, const string& str);
}
#endif
