#include "main.h"
/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the argument
 * @i: take a parameter.
 * Return: Flags:
 */

int get_flags(const char *format, int *i)

{
	int k, new;
	int flags = 0;
	const char FLAG_C[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_R[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (new = *i + 1; format[new] != '\0'; new++)
	{
		for (k = 0; FLAG_C[k] != '\0'; k++)
			if (format[new] == FLAG_C[k])
			{
				flags |= FLAG_R[k];
				break;
			}
		if (FLAG_C[k] == 0)
			break;
	}
	*i = new - 1;
	return (flags);
}
