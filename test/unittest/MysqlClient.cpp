#include "../limonp/MysqlClient.hpp"

using namespace Limonp;

bool testMysqlClient()
{
    MysqlClient client("10.16.10.32",3306,"root","mysql","cms");
    client.init();
    MysqlClient::RowsType rows;
    client.select("show tables;", rows);
    print(rows);
    return true;
}

