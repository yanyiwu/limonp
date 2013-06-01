#include "str_functs.h"

namespace CPPCOMMON
{
	string joinStr(const vector<string>& src, const string& connectorStr)
	{
		string res;
		string tmpStr;
		size_t len = src.size();
		for(size_t i = 0; i < len - 1; i++)
		{
			res += stripStr(src[i]);
			res += connectorStr;
		}
		if(0 < len)
		{
			res +=  stripStr(src[len-1]);
		}
		return res;
	}
	vector<string> splitStr(const string& source, const string& pattern)
	{
		vector<string> res;
		splitStr(source, res, pattern);
		return res;
	}
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
				string tmp = stripStr(s.substr(i, pos - i));
				if("" != tmp)
				{
					out_vec.push_back(tmp);
				}
				i = pos + pattern.size() - 1;
			}
		}
	}

	string stripStr(const string& str, const string& patternstr)
	{
		size_t leftpos = 0;
		size_t rightpos = str.size() - 1;
		while(leftpos < str.size())
		{
			if(patternstr.find(str[leftpos]) == string::npos)
			{
				break;
			}
			leftpos++;
		}
		if(leftpos == str.size())
		{
			return "";
		}
		while(rightpos > leftpos)
		{
			if(patternstr.find(str[rightpos]) == string::npos)
			{
				break;
			}
			rightpos--;
		}
		return str.substr(leftpos, rightpos - leftpos + 1);
	}
	
	bool splitStrMultiPatterns(
				const string& strSrc, 
				vector<string>& outVec, 
				const vector<string>& patterns
				)
	{
		char transChar = '#';
		int transLenThreshold = 10;
		string transStr;
		transStr += transChar;
		while(strSrc.find(transStr) != string::npos)
		{
			transStr += transChar;
			if(transStr.size() > transLenThreshold)
			  return false;
		}
		string strSrcMutable = strSrc;
		for(int i = 0; i < patterns.size(); i++)
		{
			strSrcMutable = replaceStr(strSrcMutable, patterns[i], transStr);
		}
		splitStr(strSrcMutable, outVec, transStr);
		return true;
	}

	string upperStr(const string& strIn)
	{
		string str = strIn;
		transform(str.begin(), str.end(), str.begin(), (int (*)(int))toupper);
		return str;
	}

	string lowerStr(const string& strIn)
	{
		string str = strIn;
		transform(str.begin(), str.end(), str.begin(), (int (*)(int))tolower);
		return str;
	}

	string replaceStr(const string& strSrc, const string& oldStr, const string& newStr, int count)
	{
		string strRet = strSrc;
		size_t pos = 0;
		int l_count = 0;
		if(-1 == count)
		  count = strRet.size();
		while((pos = strRet.find(oldStr, pos)) != string::npos)
		{
			strRet.replace(pos, oldStr.size(), newStr);
			if(++l_count >= count)
			  break;
			pos += newStr.size();
		}
		return strRet;
	}

	unsigned int countStrDistance(const string& A, const string& B)
	{
		unsigned int lenA = A.size();
		unsigned int lenB = B.size();
		unsigned int len = (lenA < lenB ? lenA : lenB);
		unsigned int res = lenA + lenB - 2 * len;
		for(size_t i = 0; i < len; i++)
		{
			if(A[i] != B[i])
			  res++;
		}
		return res;
	}

	unsigned int countStrSimilarity(const string& A, const string& B)
	{
		unsigned int lenA = A.size();
		unsigned int lenB = B.size();
		unsigned int len = (lenA < lenB ? lenA : lenB);
		unsigned int res = 0;
		for(size_t i = 0; i < len; i++)
		{
			if(A[i] == B[i])
			  res++;
		}
		return res;
	}
}

#ifdef TEST_STR_FUNCTS
#include <iostream>
using namespace CPPCOMMON;
using namespace std;
int main()
{
	string s = " \t\n1 a h \n";
	cout<<"["<<stripStr(s)<<"]"<<endl;
	cout<<countStrDistance("Aheheh","heheh1212")<<endl;
	cout<<joinStr(splitStr(s), ",")<<endl;
	//vector<string> vec;
	//splitStr("1 3 4", vec);
	//char * a[] = {"3","jaj","ads"};
	//vector<string> pats(a,a+3);
	//vec.clear();
	//splitStrMultiPattern("1 #3 jajs5 asdf3ads 4", vec, pats);
	//for(int i=0;i<vec.size();i++)
	//{
	//	cout<<vec[i]<<endl;
	//}
	//string s = "1111aaafasfa,asdj.sadhashfhaha";
	//upperStr(s);
	//cout<<s<<endl;
	
	//s = "ab1ba2ab3";
	//cout<<replaceStr(s,"ab","###")<<endl;
	return 0;
}
#endif
