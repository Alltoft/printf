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
	int number = 0;

	va_list(args);

	if (format == NULL)
		return (-1);
	va_start(args, format);

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
			while (*format == ' ')
				format++;
			if (*format == '\0')
				break;
			else if (*format == 'c')
			{
				char a = va_arg(args, int);

				write(1, &a, 1);
				number++;
			}
			else if (*format == 's')
			{
				char *b = va_arg(args, char *);
				int c = 0;
				if (b == NULL)
					b = "(null)";
				else
				{
				while (b[c] != '\0')
					c++;
				write(1, b, c);
				number += c;
				}
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				number++;
			}
			else
			{
				format--;
				write(1, format, 1);
				number++;
			}
		}
	format++;
	}
	va_end(args);
	return (number);
}
