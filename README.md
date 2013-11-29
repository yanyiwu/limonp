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
cmake -DCMAKE_INSTALL_PREFIX=/usr .. #如果没有-DCMAKE_INSTALL_PREFIX指定时，默认是安装到/usr/local 后面的 .. 是指cmake的CMakeLists.txt所在目录是在此目录的上一级目录
make
sudo make install
```

####验证

进入test/目录，执行

`g++ demo.cpp && ./a.out`

如果没有报错就说明安装成功

####卸载

build目录下面的`install_manifest.txt`就是这个安装的所以文件的路径，删除它们即可。

```sh
cd limonp-v.0.1.1/build/
cat install_manifest.txt | sudo xargs rm -rf
```


##使用方法

详见 test/demo.cpp

##相关声明

1.  md5.hpp 是网上搜到的一份md5.cpp/h的文件，自己修改成hpp文件。原作者信息请看代码注释。
