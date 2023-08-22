#include "main.h"
#include <unistd.h>
#include <stdarg.h>
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
	va_start(args, format);

	if (format == NULL)
		return (-1);

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
			else if (*format == 'c')
			{
				char a = va_arg(args, int);

				write(1, &a, 1);
				number++;
			}
			else if (*format == 's')
			{
				char *b = va_arg(args, char *);
				if (b == NULL)
					b = "(null)";
				else
				{
				int c = strlen(b);
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
				number ++;
			}
		}
	format++;
	}
	va_end(args);
	return (number);
}
