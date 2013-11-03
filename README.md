#Limonp 

limon + hpp 

##简介

带有明显python风格的c++处理库。

主要是一些工具函数，比如字符串处理，日志文件之类的。

比如字符串格式化，格式化日志输出。

比如print(x)来输出变量。


##依赖

文件依赖一直是很让人讨厌的东西。全做成hpp头文件形式的目的就是为了省去链接的步骤。

没有依赖，就没有伤害。

使用MysqlClient.hpp时，需要安装c语言的mysql接口库，libmysqlclient。

则链接的时候需要 -lmysqlclient

除此之外，都直接include进来即可使用。

##安装

不安装也可以使用，安装其实就是把头文件拷贝到/usr/xx(安装步骤中指定)中而已。

需要系统中有cmake这个程序，在ubuntu中安装方法是：`sudo apt-get install cmake`

###安装步骤

####安装

已安装v0.1.1版本为例:

```sh
wget https://github.com/aszxqw/limonp/archive/v.0.1.1.zip -O limonp_0.1.1.zip
unzip limonp_0.1.1.zip
cd limonp-v.0.1.1/
mkdir build
cd build/
cmake ..
make
sudo make install
```

####卸载

```sh
cd limonp-v.0.1.1/build/
cat install_manifest.txt | sudo xargs rm -rf
```

##使用方法
```sh
//g++ demo.cpp && ./a.out
//test/demo.cpp

//if installed, 
//#include <limonp/logger.cpp>
//#include <limonp/str_functs.hpp>

//not installed:
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

```

