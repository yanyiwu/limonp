
#ifndef CPPCOMMON_VEC_FUNCTS_TCC
#define CPPCOMMON_VEC_FUNCTS_TCC

#include <iostream>
#include <string>
#include <vector>
namespace CPPCOMMON
{
	using namespace std;
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
#endif

