#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * get_value - Calculates the precision for printing
 * @frmt: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_value(const char *frmt, int *i, va_list list)
{
	int new = *i + 1;
	int value = -1;

	if (frmt[new] != '.')
		return (value);

	value = 0;

	for (new += 1; frmt[new] != '\0'; new++)
	{
		if (is_digit(frmt[new]))
		{
			value *= 10;
			value += frmt[new] - '0';
		}
		else if (frmt[new] == '*')
		{
			new++;
			value = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = new - 1;

	return (value);
}
