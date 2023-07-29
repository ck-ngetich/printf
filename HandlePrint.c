#include "main.h"
#include <stdarg.h>
#include <stdio.h>

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
{'c', print_character}, {'s', print_strg}, {'%', percent_sign},
{'i', print_integer}, {'d', print_integer}, {'b', print_binr},
{'u', no_sign}, {'o', print_eight}, {'x', print_six},{'X', print_hex_caps},
{'p', print_pointer}, {'S', print_non_printable},
{'r', reverse_string}, {'R', rot13_string}, {'\0', NULL}
};
for (i = 0; fmt_types[i].fmts != '\0'; i++)
if (fmts[*ind] == fmt_types[i].fmts)
return (fmt_types[i].fnc(list, buffer, flags, width, precision, size));
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
