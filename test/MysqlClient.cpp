#include <MysqlClient.h>

using namespace Limonp;

int main()
{
    MysqlClient client("10.16.10.32",3306,"root","mysql","cms");
    client.init();
    MysqlClient::RowsType rows;
    client.select("show tables;", rows);
    FOR_VECTOR(rows, i)
    {
        cout<<vecToString(rows[i])<<endl;
    }
    return 0;
}

