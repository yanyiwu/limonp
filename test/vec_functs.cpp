/************************************
 * file enc : utf8
 * author   : wuyanyi09@gmail.com
************************************/
#include <vec_functs.hpp>

using namespace Limonp;
int main()
{
    vector<int> vec;
    for(int i=0;i<5;i++)
      vec.push_back(i);
    vector<int> pats;
    pats.push_back(0);
    pats.push_back(3);
    vector<pair<int, vector<int> > > res;
    splitVec<int>(vec,res,pats);
    cout<<isInVec<int>(vec, 0)<<endl;
    cout<<isInVec<int>(vec, -1)<<endl;
    for(unsigned int i =0;i<res.size();i++)
    {
        cout<<"first:"<<res[i].first<<endl;
        cout<<"seconde:"<<endl;
        for(unsigned int j = 0;j<res[i].second.size();j++)
        {
            cout<<res[i].second[j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
