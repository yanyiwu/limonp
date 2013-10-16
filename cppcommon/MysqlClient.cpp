#include "MysqlClient.h"

namespace CPPCOMMON
{

    bool MysqlClient::init()
    {
        cout<<mysql_get_client_info()<<endl;
        if(NULL == (_conn = mysql_init(NULL)))
        {
            LogError("mysql_init faield. %s", mysql_error(_conn));
            return false;
        }

        if (mysql_real_connect(_conn, HOST, USER, PASSWD, DB, PORT, NULL, 0) == NULL)
        {
            LogError("mysql_real_connect failed. %s", mysql_error(_conn));
            mysql_close(_conn);
            _conn = NULL;
            return false;
        }  

        return true;
    }

    bool MysqlClient::dispose()
    {
        if(NULL != _conn)
        {
            mysql_close(_conn);
        }
        _conn = NULL;
        return true;
    }

    bool MysqlClient::executeSql(const char* sql)
    {
        if(NULL == _conn)
        {
            LogError("_conn is NULL");
            return false;
        }
        if(mysql_query(_conn, sql)) 
        {
            LogError("mysql_query failed.  %s", mysql_error(_conn));
            return false;
        }
        return true;
    }
}


#ifdef UT
using namespace CPPCOMMON;

int main()
{
    MysqlClient client("127.0.0.1",3306,"root","aszxqw","test");
    client.init();
    return 0;
}

#endif
