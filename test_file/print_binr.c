#include "main.h"
/**
 * print_binary - print a given integer in binary
 * @number: an integer to be converted
 * Return: Binary of an integer
 */

int print_binary(int number)
{
	int num[32], x = 0, sum = 0;

	while (number >= 2)
	{
		num[x] = number % 2;
		number /= 2;
		x++;
	}
	num[x] = number;
	for (x; x >= 0; x--)
	{
		sum += _putchar(sum[x] + '0');
	}
	return (sum);
}
