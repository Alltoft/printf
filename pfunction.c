#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
/**
 * _printf - a func that prints everything
 * @format: what needs to be printed
 * Return: always 0
 */
int _printf(const char *format, ...)
{
	int number = 0;

	va_list(args);
	int op;

	va_start(args, format);

	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}
	while (*format)
	{
		if (*format == '\0')
			break;
		else if (*format == '%')
		{
		format++;
		op = con_func(args, *format);
		if (op == 0)
		{
			format--;
			print_c('%');
			op = 1;
		}
		number += op;
		}
		else
		{
			number += print_c(*format);
		}
	format++;
	}
	va_end(args);
	return (number);
}
