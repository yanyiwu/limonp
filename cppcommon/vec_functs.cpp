#include "vec_functs.tcc"

#ifdef TEST_VEC_FUNCTS
using namespace CPPCOMMON;
int main()
{
	vector<int> vec;
	for(int i=0;i<5;i++)
	  vec.push_back(i);
	vector<int> pats;
	//pats.push_back(1);
	pats.push_back(3);
	//pats.push_back(4);
	vector< vector<int> > res;
	splitVec<int>(vec,res,pats);
	for(int i =0;i<res.size();i++)
	{
		for(int j = 0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<endl;
		}
		cout<<endl;
	}
	return 0;
}
#endif
