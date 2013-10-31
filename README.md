#Limonp 

limon + hpp 

##内容

带有明显python风格的c++处理库。

主要是一些工具函数，比如字符串处理，日志文件之类的。

比如字符串格式化，格式化日志输出。
比如print(x)来输出变量。


##依赖


使用MysqlClient.hpp时，需要安装c语言的mysql接口库，libmysqlclient。

则链接的时候需要 -lmysqlclient

除此之外，都直接include进来即可使用。


##使用方法
```sh
//g++ demo.cpp && ./a.out
//demo.cpp

#include "limonp/logger.hpp"
#include "limonp/str_functs.hpp"

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

```

