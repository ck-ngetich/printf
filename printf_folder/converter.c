#include "main.h"



/**
 * convert - converts a number and its base into a string
 * @num: the input number
 * @base: the input base
 * @lowercase: the flag if hex values need to be in lowercase
 * Return: resulting string
 */

char *convert(unsigned long int num, int base, int lowercase)
{
static char *repl;
static char buffer[50];
char *ptr;
repl = (lowercase)
? "0123456789abcdef"
: "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do {
*--ptr = repl[num % base];
num /= base;
} while (num != 0);
return (ptr);
}
