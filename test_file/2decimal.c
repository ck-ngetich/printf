#include "main.h"
/**
 * convertToDecimal - Convert base 8 and 16 to base 10
 * @Number: an integer to be converted
 * @base: the base of an integer to be converted
 * Return: Decimal
 */

long long convertToDecimal(int Number, int base)
{
	int decnum = 0, i = 0;

	while (num != 0)
	{
		decnum += (num % 10) * power(base, i);
		++i;
		num /= 10;
	}
	i = 1;
	return (decnum);
}
