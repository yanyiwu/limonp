#include <MysqlClient.hpp>

using namespace Limonp;

int main()
{
    MysqlClient client("10.16.10.32",3306,"root","mysql","cms");
    client.init();
    MysqlClient::RowsType rows;
    client.select("show tables;", rows);
    print(rows);
    return 0;
}

