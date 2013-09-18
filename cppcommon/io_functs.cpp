/************************************
 * file enc : utf8
 * author   : wuyanyi09@gmail.com
************************************/
#include "io_functs.h"

namespace CPPCOMMON
{
    string loadFile2Str(const char * const filepath)
    {
        ifstream in(filepath);
        istreambuf_iterator<char> beg(in), end;
        string str(beg, end);
        in.close();
        return str;
    }
    
    void loadStr2File(const char * const filename, ios_base::openmode mode, const string& str)
    {
        ofstream out(filename, mode);
        ostreambuf_iterator<char> itr (out);
        copy(str.begin(), str.end(), itr);
        out.close();
    }
}
#ifdef TEST_IO_FUNCTS
#include <iostream>
using namespace CPPCOMMON;
using namespace std;
int main()
{
//    char filename[] = "1/2/3";
//    cout<<loadFile2Str("1")<<endl;
    string s = "hello world";
    loadStr2File("testfile", ofstream::app, "hello world\n");
    loadStr2File("testfile", ofstream::app, "hello world\n");
    loadStr2File("testfile", ofstream::app, "hello world\n");
    return 0;
}
#endif
