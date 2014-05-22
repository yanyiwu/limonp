[![Build Status](https://travis-ci.org/aszxqw/limonp.png?branch=master)](https://travis-ci.org/aszxqw/limonp)
- - - 

# Limonp 

## Introduction

`C++` headers(hpp) with Python style. 

## Feature

linking is a annoying thing, so I write these source code in headers file(`*.hpp`), you can use them only with `#include "xx.hpp"`, without linking *.a or *.so .

**`no linking , no hurts`** 

But except for `MysqlClient.hpp`, if you `#include "MysqlClient.hpp"`, you need linking with `-lmysqlclient`.

## Example

### `#include "StringUtil.hpp"`

`using namespace Limonp;`

#### `print`


```
string strname = "hello, world";
print(strname); //strname: hello, world.
map<string, int> mp;
mp["hello"] = 1;
mp["world"] = 2;
print(mp); // mp: {"hello": 1, "world": 2}

string res;
res << mp;
print(res); // res: {"hello": 1, "world": 2}
```

Because of having overrided `<<` operator in file `src/std_outbound.hpp`, it not only suitable for map but also can be used for `vector, set, unordered_map`.

#### `string_format`

```
string str;
string_format(str, "%s, %s", "hello", "world"); 
print(str);
//str: hello, world.
```

#### `join`

```
string str;
char * a[] = {"hello", "world"}; 
join(a, a + sizeof(a)/sizeof(a[0]), str, ",");
print(str);
//str: hello, world;
```

#### `split`

```
string str = "hello, world";
vector<string> buf;
split(str, buf, ",");
print(buf);
//buf: ["hello", "world"];
```

### `#include "Logger.hpp"`


#### `Logger`

```
LogInfo("%s, %s.", "hello", "world");
//2014-04-05 20:52:37 demo.cpp:20 INFO hello, world
```

In the same way, `LogDebug,LogWarn,LogError,LogFatal`.

### other features

see details in the code.

## Application

1. [CppJieba]


## Reference

1.  `md5.hpp` is copied from network, you can find original author in source code(in comments).
2.  `MutexLock.hpp`, `BlockingQueue.hpp`, `Condition.hpp` reference from [muduo].

## Contact

wuyanyi09@foxmail.com


[CppJieba]:https://github.com/aszxqw/cppjieba.git
[muduo]:https://github.com/chenshuo/muduo.git
