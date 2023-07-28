#include <unistd.h>
/**
 * _putchar - function to return character to stdout
 * @c: the character to print
 * Return: a character
 */

int _putchar(char c)
{
return (write(1, &c, 1));
}
