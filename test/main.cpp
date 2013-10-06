#include <iostream>
#include "../cppcommon/headers.h"
using namespace std;
using namespace CPPCOMMON;

bool utStrFunct()
{
	string s(" \t1 2 \t 3 4\t5 ");
	vector<string> vs;
	splitStr(s, vs);
	cout<<vecToString(vs)<<endl;
	s = " \t";
	splitStr(s, vs);
	cout<<vecToString(vs)<<endl;
	return true;
}

bool utArgvContext()
{
	return true;
}

int main()
{
	utStrFunct();
	return 0;
}
