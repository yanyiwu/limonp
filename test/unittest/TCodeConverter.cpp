#include "CodeConverter.hpp"
#include "StdExtension.hpp"
#include <fstream>
#include "gtest/gtest.h"

using namespace Limonp;

TEST(TCodeConverter, Utf8ToGb2312)
{
    CodeConverter cc = CodeConverter("utf-8","gb2312"); 
    string gbkdict;

    string utf8dict;
    {
        ifstream ifs("../test/testdata/dict.utf8");
        ASSERT_TRUE(ifs);
        utf8dict << ifs;
    }

    
    ASSERT_TRUE(cc.convert(utf8dict, gbkdict));

    string ans;
    {
        ifstream ifs("../test/testdata/dict.gbk");
        ASSERT_TRUE(ifs);
        ans << ifs;
    }

    ASSERT_EQ(ans, gbkdict);

}

TEST(TCodeConverter, Gb2312ToUtf8)
{
    CodeConverter cc = CodeConverter("gb2312", "utf-8"); 
    string to;

    string from;
    {
        ifstream ifs("../test/testdata/dict.gbk");
        ASSERT_TRUE(ifs);
        from << ifs;
    }
    
    ASSERT_TRUE(cc.convert(from, to));

    string ans;
    {
        ifstream ifs("../test/testdata/dict.utf8");
        ASSERT_TRUE(ifs);
        ans << ifs;
    }

    ASSERT_EQ(ans, to);
}
