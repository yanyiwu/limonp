# Limonp 

limon + hpp 

## 简介

带有明显python风格的c++处理库。

主要是一些工具函数，比如字符串处理，日志文件之类的。

比如字符串格式化，格式化日志输出。

比如print(x)来输出变量。


## 依赖

文件依赖一直是很让人讨厌的东西。全做成hpp头文件形式的目的就是为了省去链接的步骤。

**没有依赖，就没有伤害。**

使用MysqlClient.hpp时，需要安装c语言的mysql接口库，libmysqlclient。

则链接的时候需要 -lmysqlclient

除此之外，都直接include进来即可使用。

```sh
mkdir build
cd build/
cmake .. 
make
make test
```

## 使用示例



## 相关声明

1.  md5.hpp 是网上搜到的一份md5.cpp/h的文件，自己修改成hpp文件。原作者信息请看代码注释。


## 客服

wuyanyi09@foxmail.com
