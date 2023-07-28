#include "main.h"

/**
 * handle_write_char - Prints  string
 * @c: char types
 * @buffer: buffer array for print
 * @flags:  calculates active flags
 * @width: gets width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars printed
 */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
int i = 0;
char pdn = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
pdn = '0';
buffer[i++] = c;
buffer[i] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (i = 0; i < width - 1; i++)
buffer[BUFF_SIZE - i - 2] = pdn;
if (flags & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}


/**
 * write_number - prints a string
 * @is_negative: lists of args
 * @indx: char types
 * @buffer: buffer array for print
 * @flags:  calculates active flags
 * @width: gets width.
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars printed
 */
int write_number(int is_negative, int indx, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - indx - 1;
char pdn = ' ', extra_ch = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
pdn = '0';
if (is_negative)
extra_ch = '-';
else if (flags & F_PLUS)
extra_ch = '+';
else if (flags & F_SPACE)
extra_ch = ' ';
return (write_num(indx, buffer, flags, width, precision,
length, pdn, extra_ch));
}



/**
 * write_num - write a number using a bufffer
 * @indx: index at which the number starts on the buffer
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @prec: precision specifier
 * @length: number length
 * @pdn: pading char
 * @extra_ch: extra char
 * Return: Number of printed chars.
 */
int write_num(int indx, char buffer[],
int flags, int width, int prec,
int length, char pdn, char extra_ch)
{
int i, padd_start = 1;
if (prec == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0' && width == 0)
return (0); /* printf(".0d", 0)  no char is printed */
if (prec == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
buffer[indx] = pdn = ' '; /* width is displayed with padding ' ' */
if (prec > 0 && prec < length)
pdn = ' ';
while (prec > length)
buffer[--indx] = '0', length++;
if (extra_ch != 0)
length++;
if (width > length)
{
for (i = 1; i < width - length + 1; i++)
buffer[i] = pdn;
buffer[i] = '\0';
if (flags & F_MINUS && pdn  == ' ')/* Asign extra char to left of buffer */
{
if (extra_ch)
buffer[--indx] = extra_ch;
return (write(1, &buffer[indx], length) + write(1, &buffer[1], i - 1));
}
else if (!(flags & F_MINUS) && pdn == ' ')/* extra char to left of buff */
{
if (extra_ch)
buffer[--indx] = extra_ch;
return (write(1, &buffer[1], i - 1) + write(1, &buffer[indx], length));
}
else if (!(flags & F_MINUS) && pdn == '0')/* extra char to left of padd */
{
if (extra_ch)
buffer[--padd_start] = extra_ch;
return (write(1, &buffer[padd_start], i - padd_start) +
write(1, &buffer[indx], length - (1 - padd_start)));
}
}
if (extra_ch)
buffer[--indx] = extra_ch;
return (write(1, &buffer[indx], length));
}



/**
 * write_unsgnd - writes an unsigned number
 * @is_negative: indicates if the num is negative
 * @indx: index where the number starts in the buffer
 * @buffer: array of chars
 * @flags: flags specifiers
 * @width: width specifier
 * @prec: precision specifier
 * @size: size specifier
 * Return: number of written chars
 */
int write_unsgnd(int is_negative, int indx,
char buffer[],
int flags, int width, int prec, int size)
{
/* The number is stored at the bufer's right and starts at position i */
int length = BUFF_SIZE - indx - 1, i = 0;
char pdn = ' ';
UNUSED(is_negative);
UNUSED(size);
if (prec == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
return (0); /* printf(".0d", 0)  no char is printed */
if (prec > 0 && prec < length)
pdn = ' ';
while (prec > length)
{
buffer[--indx] = '0';
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
pdn = '0';
if (width > length)
{
for (i = 0; i < width - length; i++)
buffer[i] = pdn;
buffer[i] = '\0';
if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
{
return (write(1, &buffer[indx], length) + write(1, &buffer[0], i));
}
else /* Asign extra char to left of padding [pdn>buffer]*/
{
return (write(1, &buffer[0], i) + write(1, &buffer[indx], length));
}
}
return (write(1, &buffer[indx], length));
}



/**
 * write_pointer - point to memory address
 * @buffer: arrays of chars
 * @indx: index where the number starts in the buffer
 * @length: length of number
 * @width: width specifier
 * @flags: flags specifier
 * @pdn: char representing the padding
 * @extra_ch: char representing extra char
 * @padd_start: index where padding should start
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int indx, int length,
int width, int flags, char pdn, char extra_ch, int padd_start)
{
int i;
if (width > length)
{
for (i = 3; i < width - length + 3; i++)
buffer[i] = pdn;
buffer[i] = '\0';
if (flags & F_MINUS && pdn == ' ')/* Asign extra char to left of buffer */
{
buffer[--indx] = 'x';
buffer[--indx] = '0';
if (extra_ch)
buffer[--indx] = extra_ch;
return (write(1, &buffer[indx], length) + write(1, &buffer[3], i - 3));
}
else if (!(flags & F_MINUS) && pdn == ' ')/* extra char to left of buffer */
{
buffer[--indx] = 'x';
buffer[--indx] = '0';
if (extra_ch)
buffer[--indx] = extra_ch;
return (write(1, &buffer[3], i - 3) + write(1, &buffer[indx], length));
}
else if (!(flags & F_MINUS) && pdn == '0')/* extra char to left of padd */
{
if (extra_ch)
buffer[--padd_start] = extra_ch;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], i - padd_start) +
write(1, &buffer[indx], length - (1 - padd_start) - 2));
}
}
buffer[--indx] = 'x';
buffer[--indx] = '0';
if (extra_ch)
buffer[--indx] = extra_ch;
return (write(1, &buffer[indx], BUFF_SIZE - indx - 1));
}
