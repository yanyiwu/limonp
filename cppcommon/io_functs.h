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
    inline string loadFile2Str(const char * const filepath)
    {
        ifstream in(filepath);
        if(!in)
        {
            return "";
        }
        istreambuf_iterator<char> beg(in), end;
        string str(beg, end);
        in.close();
        return str;
    }
    
    inline void loadStr2File(const char * const filename, ios_base::openmode mode, const string& str)
    {
        ofstream out(filename, mode);
        ostreambuf_iterator<char> itr (out);
        copy(str.begin(), str.end(), itr);
        out.close();
    }

    inline int ReadFromFile(const char * fileName, char* buf, int maxCount, const char* mode)
    {                                        
        FILE* fp = fopen(fileName, mode);    
        if (!fp)                             
          return 0;                          
        int ret;                             
        fgets(buf, maxCount, fp) ? ret = 1 : ret = 0;                                       
        fclose(fp);                          
        return ret;                          
    }                                        

    inline int WriteStr2File(const char* fileName, const char* buf, const char* mode)
    {                                          
        FILE* fp = fopen(fileName, mode);      
        if (!fp)                               
          return 0;                            
        int n = fprintf(fp, "%s", buf);        
        fclose(fp);                            
        return n;                              
    }                                          
}
#endif
