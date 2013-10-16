#include "MysqlClient.h"

namespace CPPCOMMON
{

    bool MysqlClient::init()
    {
        //cout<<mysql_get_client_info()<<endl;
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

        //set reconenct
        char value = 1;
        mysql_options(_conn, MYSQL_OPT_RECONNECT, &value);

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

    bool MysqlClient::select(const char* sql, RowsType& rows)
    {
        if(!executeSql(sql))
        {
            LogError("executeSql failed. [%s]", sql);
            return false;
        }
        MYSQL_RES * result = mysql_store_result(_conn);
        if(NULL == result)
        {
            LogError("mysql_store_result failed.[%d]", mysql_error(_conn));
        }
        uint num_fields = mysql_num_fields(result);
        MYSQL_ROW row;
        while((row = mysql_fetch_row(result)))
        {
            vector<string> vec;
            for(uint i = 0; i < num_fields; i ++)
            {
                row[i] ? vec.push_back(row[i]) : vec.push_back("NULL");
            }
            rows.push_back(vec);
        }
        mysql_free_result(result);
        return true;
    }
}


#ifdef UT
using namespace CPPCOMMON;

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

#endif
