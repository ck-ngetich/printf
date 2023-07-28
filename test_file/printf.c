#include <stdarg.h>
#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...)
{
	int num = 0, x;
	va_list sum;

	va_start(sum, format);
	for (x = 0; format[x] != '\0'; )
	{
		if (format[x] != '%')
		{
			num += _putchar(format[x]);
			x++;
		}
		else if (format[x] == '%' && format[x + 1] != ' ')
		{
			switch (format[x + 1])
			{
				case 'c':
					num += _putchar(va_arg(data, int));
					break;
				case 's':
					num += print_string(va_arg(data, char *));
					break;
				case '%':
					num += _putchar('%');
					break;
				case 'd':
					num += print_decimal(va_arg(data, int));
					break;
				case 'i':
					num += print_decimal(va_arg(data, int));
					break;
				case 'b':
					num += print_binary(va_arg(data, int));
					break;
				case 'u':
					num += print_unsigned(va_arg(data, unsigned int));
					break;
				default:
					break
			}
			x += 2;
		}
	}
	return (num);
}
