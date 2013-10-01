#include "http_functs.h"

namespace CPPCOMMON
{
    bool parseUrl(const string& url, HashMap<string, string>& mp)
    {
        if(0 == url.length())
        {
            return false;
        }

        uint pos = url.find('?');
        uint kleft = 0, kright = 0;
        uint vleft = 0, vright = 0;
        for(uint i = pos + 1; i < url.size();)
        {
            cout<<i<<endl;
            kleft = i;
            while(i < url.size() && url[i] != '=')
            {
                i++;
            }
            if(i >= url.size())
            {
                break;
            }
            kright = i;
            i++;
            vleft = i;
            while(i < url.size() && url[i] != '&')
            {
                i++;
            }
            vright = i;
            i++;

            mp[url.substr(kleft, kright - kleft)] = url.substr(vleft, vright - vleft);

        }

        return true;
    }

    const char* const HttpReqInfo::KEY_METHOD = "METHOD";
    const char* const HttpReqInfo::KEY_PATH = "PATH";

    bool HttpReqInfo::load(const string& headerStr)
    {
        size_t len = headerStr.size();
        size_t lpos = 0, rpos = 0;
        rpos = headerStr.find(' ', lpos);
        if(!_parse(headerStr, lpos, rpos, KEY_METHOD))
        {
            LogError("parse %s faild.", key);
            return false;
        }
        lpos = rpos + 1;
        rpos = headerStr.find(' ', lpos);
        
        
        return true;
    }

    bool HttpReqInfo::_parse(const string& headerStr, size_t lpos, size_t rpos, const char * const key)
    {
        if(string::npos == rpos || rpos <= lpos)
        {
            return false;
        }
        _headerMap[KEY_METHOD] = headerStr.substr(lpos, rpos - lpos);
        return true;
    }

    bool HttpReqInfo::_methodMap(const HashMap<string, string>& mp, const string& key, string& res)
    {
        HashMap<string, string>::const_iterator it = mp.find(key);
        if(it == mp.end())
        {
            return false;
        }
        res = it->second;
        return true;
    }

}


#ifdef UT

using namespace CPPCOMMON;
int main()
{
    string url("http://127.0.0.1/?k1=v1&k2=v2 hh");
    HashMap<string, string> mp;
    parseUrl(url, mp);
    cout<<HashMapToString(mp)<<endl;
    return 0;
}

#endif
