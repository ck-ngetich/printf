#include "main.h"
/**
 * print_string - prints a string
 * Return: a string
 */
int print_string(char *string)
{
	int sum = 0;

	for (int n = 0; string[n] != '\0'; i++)
	{
		sum += _putchar(string[n]);
	}
	return (sum);
}
