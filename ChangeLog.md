# limonp ChangeLog

## v0.5.6

+ fix hidden trouble.

## v0.5.5

+ macro name LOG and CHECK in Logging.hpp is so easy to confict with other lib, so I have to rename them to XLOG and XCHECK for avoiding those macro name conflicts.

## v0.5.4

+ add ForcePublic.hpp
+ Add Utf8ToUnicode32 and Unicode32ToUtf8 in StringUtil.hpp

## v0.5.3

+ Fix incompatibility problem about 'time.h' in Windows.

## v0.5.2

+ Fix incompatibility problem about `enum {INFO ...}` name conflicts in Windows .
+ So from this version begin: the compile flags: `-DLOGGING_LEVEL=WARNING` must be changed to `-DLOGGING_LEVEL=LL_WARNING`

## v0.5.1

+ add `ThreadPool::Stop()` to wait util all the threads finished. 
If Stop() has not been called, it will be called when the ThreadPool destructing.

## v0.5.0

+ Reorganized directories: include/ -> include/limonp/ ... and so on.
+ Add `NewClosure` in Closure.hpp, 0~3 arguments have been supported.
+ Update ThreadPool, use `NewClosure` instead of `CreateTask`

## v0.4.1

+ `CHECK(exp) << "log message"` supported;

## v0.4.0

+ add test/demo.cc as example.
+ move `print` macro to StdExtension.hpp
+ BigChange: rewrite `log` module, use `LOG(INFO) << "xxx" ` instead `LogInfo` .
+ remove HandyMacro.hpp, add CHECK in Logging.hpp instead.

## v0.3.0

+ remove 'MysqlClient.hpp', 'InitOnOff.hpp', 'CastFloat.hpp'
+ add 'Closure.hpp'
+ uniform code style

## v0.2.0

+ `namespace limonp`, not `Limonp` .

## v0.1.0

+ Basic functions
