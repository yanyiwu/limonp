#include "str_functs.h"

namespace CPPCOMMON
{
	void splitStr(const string& source, vector<string>& out_vec, const string& pattern)
	{
		if(0 == pattern.size())
		{
			return;
		}
		string s = source + pattern;
		string::size_type pos;
		int length = s.size();

		for(int i = 0; i < length; i++)
		{
			pos = s.find(pattern, i);
			if(pos < length)
			{
				out_vec.push_back(s.substr(i, pos - i));
				i = pos + pattern.size() - 1;
			}
		}
	}

	void upperStr(string& str)
	{
		transform(str.begin(), str.end(), str.begin(), (int (*)(int))toupper);
	}
	void lowerStr(string& str)
	{
		transform(str.begin(), str.end(), str.begin(), (int (*)(int))tolower);
	}
}

#ifdef TEST_STR_FUNCTS
#include <iostream>
using namespace CPPCOMMON;
using namespace std;
int main()
{
	vector<string> vec;
	splitStr("1 3 4", vec);
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<endl;
	}
	string s = "1111aaafasfa,asdj.sadhashfhaha";
	upperStr(s);
	cout<<s<<endl;
	return 0;
}
#endif
