#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int current = *i + 1;
	int num = 0;

	if (format[current] == 'l')
		num = S_LONG;
	else if (format[current] == 'h')
		num = S_SHORT;

	if (num == 0)
		*i = current - 1;
	else
		*i = current;

	return (num);
}
