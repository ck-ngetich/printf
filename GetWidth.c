#include "main.h"
#include <stdarg.h>

/**
 * get_width - gets the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
int ini_i;
int width = 0;
for (ini_i = *i + 1; format[ini_i] != '\0'; ini_i++)
{
if (is_digit(format[ini_i]))
{
width *= 10;
width += format[ini_i] - '0';
}
else if (format[ini_i] == '*')
{
ini_i++;
width = va_arg(list, int);
break;
}
else
break;
}
*i = ini_i - 1;
return (width);
}
