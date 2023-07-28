#include "main.h"
/**
 * print_flags - Calculates active flags
 * @string:  Formatted string in which to print the argument
 * @i: take a parameter.
 * Return: Flags:
 */

int print_flags(const char *string, int *i)

{
	int k, new;
	int flags = 0;
	const char FLAG_C[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_R[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (new = *i + 1; string[new] != '\0'; new++)
	{
		for (k = 0; FLAG_C[k] != '\0'; k++)
			if (string[new] == FLAG_C[k])
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
