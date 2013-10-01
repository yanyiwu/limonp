#ifndef CPPCOMMON_HTTP_FUNCTS_H
#define CPPCOMMON_HTTP_FUNCTS_H

#include <iostream>
#include <string>
#include "typedefs.h"
#include "map_functs.h"
#include "str_functs.h"
#include "logger.h"

namespace CPPCOMMON
{
    using namespace std;

    class HttpReqInfo
    {
        public:
            static const char* const KEY_METHOD;
            static const char* const KEY_PATH;
        public:
            bool load(const string& headerStr);
        private:
            bool _parse(const string& headerStr, size_t lpos, size_t rpos, const char * const key);
        public:
            string& operator [](const string& key)
            {
                return _headerMap[key];
            }
        public:
            bool GET(const string& argKey, string& res)
            {
                return _methodMap(_methodGetMap, argKey, res);
            }
            bool POST(const string& argKey, string& res)
            {
                return _methodMap(_methodPostMap, argKey, res);
            }
        private:
            HashMap<string, string> _headerMap;
            HashMap<string, string> _methodGetMap;
            HashMap<string, string> _methodPostMap;
        private:
            bool _methodMap(const HashMap<string, string>& mp, const string& key, string& res);
    };

    bool parseUrl(const string& url, HashMap<string, string>& mp);
}

#endif
