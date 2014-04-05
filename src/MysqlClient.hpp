#ifndef LIMONP_MYSQLCLIENT_H
#define LIMONP_MYSQLCLIENT_H

#include <mysql.h>
#include <iostream>
#include <vector>
#include <string>
#include "logger.hpp"
#include "InitOnOff.hpp"

namespace Limonp
{
    using namespace std;
    class MysqlClient: public InitOnOff
    {
        public:
            typedef vector< vector<string> > RowsType;
        private:
            const string& HOST;
            const size_t PORT;
            const string& USER;
            const string& PASSWD;
            const string& DB;
            const string& CHARSET;
        public:
            MysqlClient(const string& host, size_t port, const string& user, const string& passwd, const string& db, const string& charset = "utf8"): HOST(host), PORT(port), USER(user), PASSWD(passwd), DB(db), CHARSET(charset), _conn(NULL)
            {
                _setInitFlag(_init());
            }
            ~MysqlClient()
            {
                if(NULL != _conn)
                {
                    mysql_close(_conn);
                }
            };
        private:
            bool _init()
            {
                //cout<<mysql_get_client_info()<<endl;
                if(NULL == (_conn = mysql_init(NULL)))
                {
                    LogError("mysql_init faield. %s", mysql_error(_conn));
                    return false;
                }

                if (mysql_real_connect(_conn, HOST.c_str(), USER.c_str(), PASSWD.c_str(), DB.c_str(), PORT, NULL, 0) == NULL)
                {
                    LogError("mysql_real_connect failed. %s", mysql_error(_conn));
                    mysql_close(_conn);
                    _conn = NULL;
                    return false;
                }  

                if(mysql_set_character_set(_conn, CHARSET.c_str()))
                {
                    LogError("mysql_set_character_set [%s] failed.", CHARSET.c_str());
                    return false;
                }

                //set reconenct
                char value = 1;
                mysql_options(_conn, MYSQL_OPT_RECONNECT, &value);

                LogInfo("MysqlClient {host: %s, database:%s, charset:%s}", HOST.c_str(), DB.c_str(), CHARSET.c_str());
                return true;
            }
        public:
            bool executeSql(const string& sql)
            {
                assert(_getInitFlag());
                if(mysql_query(_conn, sql.c_str())) 
                {
                    LogError("mysql_query failed.  %s", mysql_error(_conn));
                    return false;
                }
                return true;
            }
            size_t insert(const string& tableName, const string& keys, const vector<string>& vals)
            {
                size_t retn = 0;
                string sql;
                for(uint i = 0; i < vals.size(); i ++)
                {
                    sql.clear();
                    string_format(sql, "insert into %s (%s) values %s", tableName.c_str(), keys.c_str(), vals[i].c_str());
                    retn += executeSql(sql.c_str());
                }
                return retn;
            }
            bool select(const string& sql, RowsType& rows)
            {
                if(!executeSql(sql))
                {
                    LogError("executeSql failed. [%s]", sql.c_str());
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

        private:
            MYSQL * _conn;

    };
}

#endif
