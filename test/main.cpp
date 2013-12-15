#include "../limonp/cast_functs.hpp"

using namespace std;
using namespace Limonp;

bool testCastFunct()
{
    for(short i = -128 ; i <= 127; i++)
    {
        float f = shortBitsToFloat(i);
        cout<<i<<" "<<f<<endl;
    }
    return true;
}


void test()
{
    typedef bool (*ptTestFunct)();
    ptTestFunct arr[] = {}
}

int main()
{
    test();
	return 0;
}
