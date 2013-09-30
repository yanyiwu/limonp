#ifndef CPPCOMMON_HTTP_FUNCTS_H
#define CPPCOMMON_HTTP_FUNCTS_H

#include <iostream>
#include <string>
#include "typedefs.h"
#include "map_functs.h"
namespace CPPCOMMON
{
    using namespace std;
    bool parseUrl(const string& url, HashMap<string, string>& mp);
}

#endif
