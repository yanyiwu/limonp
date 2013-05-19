#ifndef CPPCOMMON_VEC_FUNCTS_H
#define CPPCOMMON_VEC_FUNCTS_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include "vec_functs.tcc"

#define PRINT_VECTOR(vec) for(size_t i = 0; i < vec.size(); i++) \
{\
	cout<<vec[i]<<endl;\
}

#define PRINT_MATRIX(mat) for(size_t i = 0; i < mat.size(); i++) \
{\
	for(size_t j = 0; j < mat[i].size(); j++)\
	{\
		cout<<mat[i][j]<<endl;\
	}\
}

namespace CPPCOMMON
{
	using namespace std;
}
#endif
