/************************************
 * file enc : utf8
 * author   : wuyanyi09@gmail.com
 ************************************/
#include <str_functs.hpp>
#include <map_functs.hpp>

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
    s = "";
    cout<<string_format("select %s from %s  %s;", "*","table1","limit 1")<<endl;
    string_format(s, "select %s from %s  %s;", "*","table1","limit 1");
    cout<<s<<endl;
    vec.clear();
    vec.push_back("1");
    vec.push_back("2");
    vec.push_back("3");
    s.clear();
    join(vec.begin(), vec.end(), s,",");
    print(s);
    s.clear();
    print(join(vec.begin(), vec.end(), ".."));
    const char* arr[3] = {"2","3","5"};
    print(join(arr, arr+3, ","));
    map<string , int> mp;
    mp["key1"] =2;
    print(mp);
    s <<  mp;
    print(s);
    HashMap<int,int> hmp;
    hmp[1]=2;
    print(hmp);
    return 0;
}
