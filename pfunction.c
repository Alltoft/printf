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
		if (*format != '%')
		{
			write(1, format, 1);
			number++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			op = con_func(args, *format);
			number += op;
		}
	format++;
	}
	va_end(args);
	printf("%d\n", number);
	return (number);
}
