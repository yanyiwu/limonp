/************************************
 * file enc : utf8
 * author   : wuyanyi09@gmail.com
************************************/
#ifndef CPPCOMMON_FILE_FUNCTS_H
#define CPPCOMMON_FILE_FUNCTS_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
namespace CPPCOMMON
{
    using namespace std;
    inline bool checkFileExist(const string& filePath)
    {
        fstream _file;
        _file.open(filePath.c_str(), ios::in);
        if(_file)
          return true;
        return false;
    }

    inline bool createDir(const string& dirPath, bool p = true)
    {
        string dir_str(dirPath);
        string cmd = "mkdir";
        if(p)
        {
            cmd += " -p";
        }
        cmd += " " + dir_str; 
        int res = system(cmd.c_str());
        return res;
    }

    inline bool checkDirExist(const string& dirPath)
    {
        return checkFileExist(dirPath);
    }

}

#endif
