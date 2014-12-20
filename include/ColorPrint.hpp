#ifndef LIMONP_COLOR_PRINT_HPP
#define LIMONP_COLOR_PRINT_HPP

#include <string>

namespace Limonp
{
    using std::string;

    enum COLOR
    {
        BLACK = 30,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        PURPLE
    };
    
    static void ColorPrint(const string& str, enum COLOR color = GREEN)
    {
        printf("\033[0;%dm%s\033[0m", color, str.c_str());
    }
}


#endif
