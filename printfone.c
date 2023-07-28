#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_character - Prints a char
 * @list: List a of arguments
 * @array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Width
 * @digit: Precision specification
 * @sizes: Size specifier
 * Return: Number of chars printed
 */
int print_character(va_list list, char array[],
	int flag, int width, int digit, int sizes)
{
	char c = va_arg(list, int);

	return (handle_write_char(c, array, flag, width, digit, sizes));
}

/**
 * print_strg - Prints a string
 * @type: List a of arguments
 * @buffers: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @value: Precision specification
 * @sizes: Size specifier
 * Return: Number of chars printed
 */
int print_strg(va_list type, char buffers[],
	int flag, int width, int value, int sizes)
{
	int length = 0, i;
	char *str = va_arg(type, char *);

	UNUSED(buffers);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(value);
	UNUSED(sizes);
	if (str == NULL)
	{
		str = "(null)";
		if (value >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (value >= 0 && value < length)
		length = value;
	if (width > length)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
/**
 * percent_sign - Prints a percent sign
 * @type: Lista of arguments
 * @array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @value: Precision specification
 * @sizes: Size specifier
 * Return: Number of chars printed
 */
int percent_sign(va_list type, char array[],
	int flag, int width, int value, int sizes)
{
	UNUSED(type);
	UNUSED(array);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(value);
	UNUSED(sizes);
	return (write(1, "%%", 1));
}
/**
 * print_integer - Print integer
 * @list: List of arguments
 * @array: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @digit: Precision specification
 * @sizes: Size specifier
 * Return: Number of chars printed
 */
int print_integer(va_list list, char array[],
	int flags, int width, int digit, int sizes)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(list, long int);
	unsigned long int num;

	n = convert_size_number(n, sizes);
	if (n == 0)
		array[i--] = '0';

	array[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		array[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, array, flags, width, digit, sizes));
}
/**
 * print_binr - Prints an unsigned number
 * @types: Lista of arguments
 * @array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @value: Precision specification
 * @number: Size specifier
 * Return: Numbers of char printed.
 */
int print_binr(va_list types, char array[],
	int flag, int width, int value, int number)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(array);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(value);
	UNUSED(number);
	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
