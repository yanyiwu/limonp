#include "encoding.h"

namespace CPPCOMMON
{
	const string& UnicodeEncoding::UTF8ENC = "utf-8";
	const string& UnicodeEncoding::GBKENC = "gbk";
	
	UnicodeEncoding::UnicodeEncoding()
	{
		_encVec.push_back(UTF8ENC);
		_encVec.push_back(GBKENC);
		_encoding = UTF8ENC;
	}

	UnicodeEncoding::~UnicodeEncoding()
	{
	}
	
	bool UnicodeEncoding::setEncoding(const string& enc)
	{
		if(!isInVec<string>(_encVec, enc))
		{
			return false;
		}
		_encoding = enc;
		return true;
	}
	string UnicodeEncoding::encode(const string& str)
	{
		if(str.empty())
		{
			return "";
		}
		if(UTF8ENC == _encoding)
		{
			return unicodeToUtf8(str);
		}
		else if(GBKENC  == _encoding)
		{
			return utf8ToGbk(unicodeToUtf8(str));
		}
		return "";
	}
	string UnicodeEncoding::decode(const string& str)
	{
		if(str.empty())
		{
			return "";
		}
		if(UTF8ENC == _encoding)
		{
			return utf8ToUnicode(str);
		}
		else if(GBKENC == _encoding)
		{
			return utf8ToUnicode(gbkToUtf8(str));
		}
		return "";
	}
}

#ifdef ENCODING_UT
using namespace CPPCOMMON;
int main()
{
	UnicodeEncoding enc;
	
	return 0;
}

#endif
