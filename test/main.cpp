#include <iostream>
#include "../src/headers.h"
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
	const char *argv[] = {"./main","key1","--hehe", "1", "-help", "2", "key2", "key3"};
	int argc = 8;
	ArgvContext arg(argc, argv);
	cout<<arg.toString()<<endl;
	cout<<arg[1]<<endl;
	cout<<arg["--hehe"]<<endl;
	cout<<pairToString<int,double>(pair<int, double>(1,1.2))<<endl;
	cout<<arg.isKeyExist("-help")<<endl;
	cout<<arg.getSize()<<endl;
	return true;
}

int main()
{
	utStrFunct();
	utArgvContext();
	return 0;
}
