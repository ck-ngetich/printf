#include "main.h"



/**
 * _printf - outputs input according to a given format
 * @format: format string containing the specifiers
 * this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of formatted output string
 */

int _printf(const char *format, ...)
{
int (*prFunc)(va_list, flags_t *);
const char *p;
va_list argp;
flags_t flags = {0, 0, 0};
register int count = 0;

va_start(argp, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = format; *p; p++)
{
if (*p == '%')
{
p++;
if (*p == '%')
{
count += _putchar('%');
continue;
}
while (get_flag(*p, &flags))
p++;
prFunc = get_print(*p);
count += (prFunc)
? prFunc(argp, &flags)
: _printf("%%%c", *p);
}
else
count += _putchar(*p);
}
putchar(-1);
va_end(argp);
return (count);
}
