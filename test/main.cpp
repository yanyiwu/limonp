#include <iostream>
#include <cast_functs.hpp>
#include <str_functs.hpp>
#include <MysqlClient.hpp>

using namespace std;
using namespace Limonp;

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
    //utCastFunct();
    //utMysqlClient();
	return 0;
}
