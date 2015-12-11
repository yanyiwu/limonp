#ifndef LIMONP_HANDY_MACRO_HPP
#define LIMONP_HANDY_MACRO_HPP

#include <cstdio>
#include <cstdlib>

#define LIMONP_CHECK(exp) \
    if(!(exp)){fprintf(stderr, "File:%s, Line:%d Exp:[" #exp "] is true, abort.\n", __FILE__, __LINE__); abort();}

#endif
