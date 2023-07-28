#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char c = 0, gap = ' ';
	int size_c = BUFF_SIZE - 2, len = 2, start = 1;
	unsigned long address;
	char rept[] = "0123456789abcdef";
	void *numbers = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);
	if (numbers == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	address = (unsigned long)numbers;
	while (address > 0)
	{
		buffer[size_c--] = rept[address % 16];
		address /= 16;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		gap = '0';
	if (flags & F_PLUS)
		c = '+', len++;
	else if (flags & F_SPACE)
		c = ' ', len++;
	size_c++;
	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, size_c, len,
		width, flags, gap, c, start));
}
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = 0, equal = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[k] != '\0')
	{
		if (is_printable(str[k]))
			buffer[k + equal] = str[k];
		else
		equal += append_hexa_code(str[k], buffer, k + equal);
		k++;
	}

	buffer[k + equal] = '\0';

	return (write(1, buffer, k + equal));

}

/**
 * reverse_string - Prints reverse string.
 * @list: List of arguments
 * @array: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @digit: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int reverse_string(va_list list, char array[],
	int flags, int width, int digit, int size)
{
	char *ch;
	int j, num = 0;

	UNUSED(array);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	ch = va_arg(list, char *);
	if (ch == NULL)
	{
		UNUSED(digit);
		ch = ")Null(";
	}

	for (j = 0; ch[j]; j++)


	for (j = j - 1; j >= 0; j--)
	{
		char s = ch[j];

		write(1, &s, 1);
		num++;
	}
	return (num);
}

/**
 * rot13_string - Print a string in rot13.
 * @list: Lista of arguments
 * @array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @digit: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int rot13_string(va_list list, char array[],
	int flag, int width, int digit, int size)
{
	char x;
	char *strg;
	unsigned int m, n;
	int number = 0;
	char enter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char exit[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	strg = va_arg(list, char *);
	UNUSED(array);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(digit);
	UNUSED(size);
	if (strg == NULL)
		strg = "(AHYY)";
	for (m = 0; strg[m]; m++)
	{
		for (n = 0; enter[n]; n++)
		{
			if (enter[n] == strg[m])
			{
				x = exit[n];
				write(1, &x, 1);
				number++;
				break;
			}
		}
		if (!exit[n])
		{
			x = strg[m];
			write(1, &x, 1);
			number++;
		}
	}
	return (number);
}
