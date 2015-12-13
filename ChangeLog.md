# limonp ChangeLog

## next version

+ Reorganized directories: include/ -> include/limonp/ ... and so on.

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
