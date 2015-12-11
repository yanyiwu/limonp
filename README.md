[![Build Status](https://travis-ci.org/yanyiwu/limonp.png?branch=master)](https://travis-ci.org/yanyiwu/limonp)
- - - 

# limonp 

## Introduction

`C++` headers(hpp) with Python style. 

## Feature

+ linking is a annoying thing, so I write these source code in headers file(`*.hpp`), you can use them only with `#include "xx.hpp"`, without linking *.a or *.so .

**`no linking , no hurts`** 

## Example

See Details in `test/demo.cpp`

## Cases

1. [CppJieba]

## Reference

1.  `md5.hpp` is copied from network, you can find original author in source code(in comments).
2.  `MutexLock.hpp`, `BlockingQueue.hpp`, `Condition.hpp` reference from [muduo].

## Contact

+ i@yanyiwu.com

[CppJieba]:https://github.com/yanyiwu/cppjieba.git
[muduo]:https://github.com/chenshuo/muduo.git
