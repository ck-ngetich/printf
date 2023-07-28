#include "main.h"
/**
 * print_unsigned - print the unsigned integer
 * @value: the value of an integer used
 * Return: unsigned integer
 */
int print_unsigned(unsigned int value)
{
	int number = 0;

	if (value / 10)
		number += print_decimal(value / 10);
	number += _putchar(value % 10 + '0');
	return (number);
}
