#include "main.h"
/**
 * print_decimal - print a decimal of a number
 * Return: decimal of a number
 */
int print_decimal(int value)
{
int sum = 0;/* print '-' for negative numbers */

if (value < 0)
{
sum += _putchar('-');
value = value * -;
}
if (value / 10)
sum += print_decimal(value / 10);
sum += _putchar(value % 10 + '0');
return (sum);
}
