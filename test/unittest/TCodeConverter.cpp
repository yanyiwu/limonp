#include "CodeConverter.hpp"
#include "StdExtension.hpp"
#include <fstream>
#include "gtest/gtest.h"

using namespace Limonp;

struct ArgType
{
    CodeConverter* cc;
    string from;
};

static void* worker(void * arg)
{
    ArgType* a = (ArgType*) arg;
    string res;
    usleep(10);
    bool ret = a->cc->convert(a->from, res);
    assert(ret);
    return NULL;
};

TEST(TCodeConverter, ThreadSafety)
{
    CodeConverter cc = CodeConverter("utf-8","gb2312"); 
    string from, to;
    ifstream ifs("../test/testdata/dict.utf8");
    string line;
    ArgType arg;
    arg.cc = &cc;
    size_t thread_num = 5;
    while(getline(ifs, arg.from))
    {
        for(size_t i = 0 ;i < thread_num; i++)
        {
            pthread_t p;
            ASSERT_EQ(0, pthread_create(&p, NULL, worker, &arg));
            ASSERT_EQ(0, pthread_join(p, NULL));
        }
    }
}

TEST(TCodeConverter, Utf8ToGb2312)
{
    string to;
    CodeConverter cc = CodeConverter("utf-8","gb2312"); 

    string from;
    {
        ifstream ifs("../test/testdata/dict.utf8");
        ASSERT_TRUE(!!ifs);
        from << ifs;
    }

    ASSERT_TRUE(cc.convert(from, to));

    string ans;
    {
        ifstream ifs("../test/testdata/dict.gbk");
        ASSERT_TRUE(!!ifs);
        ans << ifs;
    }

    ASSERT_EQ(ans, to);

}

TEST(TCodeConverter, Gb2312ToUtf8)
{
    CodeConverter cc = CodeConverter("gb2312", "utf-8"); 
    string to;

    string from;
    {
        ifstream ifs("../test/testdata/dict.gbk");
        ASSERT_TRUE(!!ifs);
        from << ifs;
    }
    
    ASSERT_TRUE(cc.convert(from, to));

    string ans;
    {
        ifstream ifs("../test/testdata/dict.utf8");
        ASSERT_TRUE(!!ifs);
        ans << ifs;
    }

    ASSERT_EQ(ans, to);
}

TEST(TCodeConverter, performance1)
{
    string from;
    {
        ifstream ifs("../test/testdata/dict.utf8");
        ASSERT_TRUE(!!ifs);
        from << ifs;
    }
    string to;
    for(size_t i = 0; i < 50000; i++)
    {
        ASSERT_TRUE(code_convert("utf-8", "gb2312", from, to));
    }
}
TEST(TCodeConverter, performance2)
{
    string from;
    string to;
    {
        ifstream ifs("../test/testdata/dict.utf8");
        ASSERT_TRUE(!!ifs);
        from << ifs;
    }
    CodeConverter cc = CodeConverter("utf-8","gb2312"); 
    for(size_t i = 0; i < 50000; i++)
    {
        ASSERT_TRUE(cc.convert(from, to));
    }
}
