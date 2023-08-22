#include <unistd.h>
#include <stdio.h>
#include <string.h>
/**
 * print_i - print integer
 * @n: a number
 * Return: length of str
 */
int print_i(int n)
{
	char str[20];

	sprintf(str, "%d", n);
	write(1, str, strlen(str));
	return (strlen(str));
}
