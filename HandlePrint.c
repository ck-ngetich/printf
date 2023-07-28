#include "main.h"
#include <stdarg.h>


/**
 * handle_print - Prints an argument based on its type
 * @fmts: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmts, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
int i, unkn_len = 0, printed_chars = -1;
fmt_t fmt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (i = 0; fmt_types[i].fmts != '\0'; i++)
if (fmts[*ind] == fmt_types[i].fmts)
return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
if (fmt_types[i].fmts == '\0')
{
if (fmts[*ind] == '\0')
return (-1);
unkn_len += write(1, "%%", 1);
if (fmts[*ind - 1] == ' ')
unkn_len += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fmts[*ind] != ' ' && fmts[*ind] != '%')
--(*ind);
if (fmts[*ind] == ' ')
--(*ind);
return (1);
}
unkn_len += write(1, &fmts[*ind], 1);
return (unkn_len);
}
return (printed_chars);
}
