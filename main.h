#ifndef HEAD_H
#define HEAD_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
int _printf(const char *format, ...);
int con_func(va_list args, char inp);
#endif
