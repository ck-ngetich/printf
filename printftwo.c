#include "main.h"
#include <stdarg.h>

/**
 * print_hex_caps - Prints an unsigned number in upper hexadecimal notation
 * @list: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed

 */

int print_hex_caps(va_list list, char buffer[],
        int flags, int width, int precision, int size)
{
        return (print_hex(list, "0123456789ABCDEF", buffer,
                flags, 'X', width, precision, size));
}
/**
 * no_sign - Prints an unsigned number
 * @list: List a of arguments
 * @array: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @value: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int no_sign(va_list list, char array[],
	int flags, int width, int value, int size)

{
	int x = BUFF_SIZE - 2;
	unsigned long int number = va_arg(list, unsigned long int);

	number = convert_size_unsgnd(number, size);
	if (number == 0)

		array[x--] = '0';
	array[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		array[x--] = (number % 10) + '0';
		number /= 10;
	}
	x++;
	return (write_unsgnd(0, x, array, flags, width, value, size));
}

/**
 * print_eight - Prints an unsigned number in octal notation
 * @type: Lista of arguments
 * @array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width
 * @value: Precision specification
 * @sizes: Size specifier
 * Return: Number of chars printed
 */
int print_eight(va_list type, char array[],
	int flag, int width, int value, int sizes)
{

	int k = BUFF_SIZE - 2;
	unsigned long int number = va_arg(type, unsigned long int);
	unsigned long int first_count = number;

	UNUSED(width);
	number = convert_size_unsgnd(number, sizes);
	if (number == 0)
		array[k--] = '0';

	array[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		array[k--] = (number % 8) + '0';
		number /= 8;
	}
	if (flag & F_HASH && first_count != 0)
		array[k--] = '0';
	k++;
	return (write_unsgnd(0, k, array, flag, width, value, sizes));
}

/**
 * print_six - Prints an unsigned number in hexadecimal notation
 * @list: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @digit: Precision specification
 * @sizes: Size specifier
 * Return: Number of chars printed
 */
int print_six(va_list list, char buffer[],
	int flags, int width, int digit, int sizes)
{
	return (print_hex(list, "0123456789abcdef", buffer,
		flags, 'x', width, digit, sizes));
}

/**
 * print_hex - Prints a hexadecimal number in lower or upper
 * list: List of arguments
 * @rep: Array of values to map the number to
 * @array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @f_character: Calculates active flags
 * @width: get width
 * @value: Precision specification
 * @size: Size specifier
 * @sizes: Size specification
 * Return: Number of chars printed
 */
int print_hex(va_list list, char rep[], char array[],
	int flag, char f_character, int width, int value, int sizes)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, sizes);
	if (num == 0)
		array[i--] = '0';
	array[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		array[i--] = rep[num % 16];
		num /= 16;
	}
	if (flag & F_HASH && init_num != 0)
	{
		array[i--] = f_character;
		array[i--] = '0';
	}

	i++;
	return (write_unsgnd(0, i, array, flag, width, value, sizes));
}
