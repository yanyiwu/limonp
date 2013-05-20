#ifndef CPPCOMMON_STR_FUNCTS_H
#define CPPCOMMON_STR_FUNCTS_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
namespace CPPCOMMON
{
	using namespace std;
	void splitStr(const string& source, vector<string>& out_vec, const string& pattern = " ");
	bool splitStrMultiPatterns(
				const string& strSrc, 
				vector<string>& outVec, 
				const vector<string>& patterns
				);
	string upperStr(const string& str);
	string lowerStr(const string& str);
	string replaceStr(const string& strSrc, const string& oldStr, const string& newStr, int count = -1);
	string stripStr(const string& str, const string& patternstr = " \n\t");
}
#endif
