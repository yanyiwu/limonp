#ifndef LIMONP_COLOR_PRINT_HPP
#define LIMONP_COLOR_PRINT_HPP

#include <string>
#include <stdarg.h>

namespace Limonp {
using std::string;

enum COLOR {
  BLACK = 30,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  PURPLE
};

static void ColorPrint(enum COLOR color, const char * fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  printf("\033[0;%dm", color);
  vprintf(fmt, ap);
  printf("\033[0m");
  va_end(ap);
}

static void ColorPrint(const string& str, enum COLOR color = GREEN) {
  printf("\033[0;%dm%s\033[0m", color, str.c_str());
}

} // namespace Limonp

#endif
