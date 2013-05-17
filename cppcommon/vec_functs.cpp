#include "vec_functs.h"

namespace CPPCOMMON
{
	template<typename T>
	void splitVec(const vector<T>& vecSrc, vector< vector<T> >& outVec, const vector<T>& patternVec)
	{
		//queue<size_t> posQue;
		//typedef typename vector<T>::iterator iterType;
		//queue< iterType > posQue;
		vector<T> tmp;
		for(size_t i = 0; i < vecSrc.size(); i++)
		//for(iterType it = vecSrc.begin(); it != vecSrc.end(); it++)
		{
			bool flag = false;
			for(size_t j = 0; j < patternVec.size(); j++)
			{
				if(patternVec[j] == vecSrc[i])
				{
					flag = true;
					break;
				}
			}
			if(flag)
			{
				//posQue.push(i);
				//cout<<it<<endl;
				if(!tmp.empty())
				{
					outVec.push_back(tmp);
					tmp.clear();
				}
			}
			else
			{
				tmp.push_back(vecSrc[i]);
			}
			//typedef typename vector<T>::iterator iterType;
			//iterType it = find(patternVec.begin(), patternVec.end(), vecSrc[i]);
			//if(it != patternVec.end())
			//{
			//	posVec.push_back(i);
			//}
		}
		if(!tmp.empty())
		{
			outVec.push_back(tmp);
		}
		/*if(posQue.empty())
		{
			outVec.push_back(vector<T>(vecSrc.begin(),vecSrc.end()));
			return;
		}*/
		/*size_t left = 0;
		size_t right;
		//iterType left = vecSrc.begin();
		vector<T> tmp;
		while(!posQue.empty())
		{
			right = posQue.pop();
			tmp.clear();
			for(size_t i = left; i < right; i++)
			{
				tmp.push_back(vecSrc[i]);
			}
			outVec.push_back(tmp);
			left = right;
		}
		right = vecSrc.size();
		tmp.clear();
		for(size_t i = left; i < right; i++)
		{
			tmp.push_back(vecSrc[i]);
		}
		outVec.push_back(tmp);*/
	}
	
}

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
