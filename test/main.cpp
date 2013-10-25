#include <iostream>
#include <vec_functs.hpp>
#include <cast_functs.hpp>
#include <str_functs.hpp>
using namespace std;
using namespace Limonp;

bool utStrFunct()
{
	string s(" \t1 2 \t 3 4\t5 ");
	vector<string> vs;
	splitStr(s, vs, "\t");
	cout<<vecToString(vs)<<endl;
	s = " \t";
	splitStr(s, vs, "\t");
	cout<<vecToString(vs)<<endl;
	return true;
}

bool utCastFunct()
{
    for(short i = -128 ; i <= 127; i++)
    {
        float f = shortBitsToFloat(i);
        cout<<i<<" "<<f<<endl;
    }
    return true;
}

bool utArgvContext()
{
	return true;
}

//bool utMysqlClient()
//{
//    MysqlClient client("10.16.10.32",3306,"root","mysql","cms");
//    client.init();
//    MysqlClient::RowsType rows;
//    client.select("show tables;", rows);
//    FOR_VECTOR(rows, i)
//    {
//        cout<<vecToString(rows[i])<<endl;
//    }
//    return true;
//}

int main()
{
	utStrFunct();
    utCastFunct();
    //utMysqlClient();
	return 0;
}
