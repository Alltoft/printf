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

	switch (inp)
	{
		case 'c':
			return (print_c(va_arg(args, int)));
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
				str = "";
			return (write(1, str, strlen(str)));
		case '%':
			return (write(1, &inp, 1));
		case 'd':
		case 'i':
			return (print_i(va_arg(args, int)));
		case 'u':
			return (print_i(va_arg(args, int)));
		default:
			return (0);
			
	}
}
