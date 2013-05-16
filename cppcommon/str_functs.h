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
	void upperStr(string& str);
}
#endif
