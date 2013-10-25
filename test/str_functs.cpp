/************************************
 * file enc : utf8
 * author   : wuyanyi09@gmail.com
 ************************************/
#include <str_functs.hpp>

#include <iostream>
using namespace Limonp;
using namespace std;
int main()
{
    vector<string> vec;
    splitStr("\t1\t3\t4\t", vec, "\t");
	cout<<vec.size()<<endl;
    for(uint i =0;i < vec.size(); i++)
    {
        cout<<vec[i]<<endl;
    }
    cout<<strStartsWith("--help","--")<<endl;
    cout<<strStartsWith("--help","-")<<endl;
    cout<<strStartsWith("--help","he")<<endl;
    cout<<strStartsWith("help","help")<<endl;
    cout<<strStartsWith("","help")<<endl;
    cout<<strStartsWith("hel","")<<endl;
    cout<<strEndsWith("hel","")<<endl;
    cout<<strEndsWith("hel","el")<<endl;
    //string s(" \t\n ni hao ad \r\n");
    string s;
    cout<<":::"<<trim(s)<<":::"<<endl;
    return 0;
}
