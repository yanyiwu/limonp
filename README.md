# limonp 

[![Build Status](https://travis-ci.org/yanyiwu/limonp.png?branch=master)](https://travis-ci.org/yanyiwu/limonp)
[![Author](https://img.shields.io/badge/author-@yanyiwu-blue.svg?style=flat)](http://yanyiwu.com/) 
[![Platform](https://img.shields.io/badge/platform-Linux,%20OS%20X,%20Windows-green.svg?style=flat)](https://github.com/yanyiwu/limonp)
[![License](https://img.shields.io/badge/license-MIT-yellow.svg?style=flat)](http://yanyiwu.mit-license.org)

[![logo](http://images.yanyiwu.com/LimonpLogo-v1.png)](https://github.com/yanyiwu/limonp)

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

