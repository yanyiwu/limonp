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
