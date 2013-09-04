#include <iostream>
#include "../src/headers.h"
using namespace std;
using namespace CPPCOMMON;

bool strFunctUt()
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

int main()
{
	strFunctUt();
	return 0;
}
