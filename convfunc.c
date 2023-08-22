#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
/**
 * con_func - it see wich to convert
 * @args: for va_* function
 * @inp: is the input
 * Return: result
 */
int con_func(va_list args, char inp)
{
	char *str;
	char a;
	char b;
	char c;

	switch (inp)
	{
		case 'c':
			a = va_arg(args, int);
			return (write(1, &a, 1));
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
				str = "";
			return (write(1, str, strlen(str)));
		case '%':
			return (write(1, &inp, 1));
		case 'd':
		case 'i':
			b = va_arg(args, int);
			return (write(1, &b, 1));
		case 'u':
			c = va_arg(args, int);
			return (write(1, &c, 1));
		default:
			if (inp == ' ')
			{
				while (inp == ' ')
					inp++;
			}
			inp--;
			return (write(1, &inp, 1));
	}
}
