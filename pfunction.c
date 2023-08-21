#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - a func that prints everything
 * @format: what needs to be printed
 * Return: always 0
 */
int _printf(const char *format, ...)
{
	va_list(args);

	va_start(args, format);
	write(1, format, strlen(format));
	va_end(args);

	return (0);
}
