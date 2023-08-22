#include <unistd.h>
/**
 * print_c - prints a character
 * @a: the character
 * Return: 1 means succee
 */
int print_c(char a)
{
	write(1, &a, 1);
	return (1);
}
