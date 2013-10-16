#ifndef CPPCOMMON_MYSQLCLIENT_H
#define CPPCOMMON_MYSQLCLIENT_H

#include <mysql/mysql.h>
#include <iostream>
#include <vector>
#include <string>
#include "logger.h"
#include "vec_functs.h"

namespace CPPCOMMON
{
    using namespace std;
    class MysqlClient
    {
        public:
            typedef vector< vector<string> > RowsType;
        private:
            const char * const HOST;
            const unsigned int PORT;
            const char * const USER;
            const char * const PASSWD;
            const char * const DB;
        public:
            MysqlClient(const char* host, uint port, const char* user, const char* passwd, const char* db):
                HOST(host), PORT(port), USER(user), PASSWD(passwd), DB(db)
        {
            _conn = NULL;
        };
            ~MysqlClient(){dispose();};
        public:
            bool init();
            bool dispose();
            bool executeSql(const char* sql);
            bool select(const char* sql, RowsType& rows);

        private:
            MYSQL * _conn;

    };
}

#endif
