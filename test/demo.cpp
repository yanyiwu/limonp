
#include <Limonp/logger.hpp>
#include <Limonp/str_functs.hpp>

using namespace Limonp;

//just for demo
struct St
{
    int i;
    double d;
    vector<string> v;
};

ostream& operator << (ostream& os, const St& s)
{
    return os << "{i:" << s.i << ", d:" << s.d << "v:" << s.v << "}";
}

int main()
{
    //logger.hpp usage;
    {
        LogInfo("I am from %s, id: %d", "TianChao", 101);
        //this same as LogDebug && LogWarn && LogError && LogFatal 
    }

    //print
    {
        vector<string> vs;
        vs.push_back("first");
        vs.push_back("second");
        vs.push_back("third");
        print(vs);

        map<string, int> mp;
        mp["k1"] = 1;
        mp["k2"] = 2;
        print(mp);
        print(join(mp.begin(), mp.end(), "/"));

        string s;
        s << mp;
        print(s);
        //the same as set<T> , vector< vector<T> >  ...
        struct St st;
        st.i = 1;
        st.d = 2.0;
        st.v = vs;
        print(st);


        s << st;
        print(s);
    }

    return 0;
}
