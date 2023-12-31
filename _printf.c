#include "main.h"
#include <stdarg.h>
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int x, print = 0, pchars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			pchars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = print_flags(format, &x);
			width = get_width(format, &x, list);
			precision = get_value(format, &x, list);
			size = get_size(format, &x);
			++x;
			print = handle_print(format, &x, list, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			pchars += print;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (pchars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
