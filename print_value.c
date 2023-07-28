#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int new = *i + 1
	int value = -1;

	if (format[new] != '.')
		return (value);

	value = 0;

	for (new += 1; format[new] != '\0'; new++)
	{
		if (is_digit(format[new]))
		{
			value *= 10;
			value += format[new] - '0';
		}
		else if (format[new] == '*')
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
