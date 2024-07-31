#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(const char *str);
int print_int(int n);
int handle_format(const char **format, va_list args);

#endif /* MAIN_H */


