#include "../main.h"
#include <stdio.h>
/**
  * main - A main to tests %c and %s cases in _printf()
  * vs. printf()
  *
  * Return: Always zero.
  */
int main(void)
{
	int i = 0, j = 0;

	i = printf("Expected output:    %cAAA\n", 'a');
	j = _printf("Current output:     %cAAA\n", 'a');
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);
	i = printf("Expected output:    %cc\n", 'a');
	j = _printf("Current output:     %cc\n", 'a');
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);
	i = printf("Expected output:    %yd\n");
	j = _printf("Current output:     %yd\n");
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);
	i = printf("Expected output:    %c\n", 53);
	j = _printf("Current output:     %c\n", 53);
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);
	i = printf("Expected output:    %c\n", '\0');
	j = _printf("Current output:     %c\n", '\0');
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);
	i = printf("Expected output:    %%%c\n", 'y');
	j = _printf("Current output:     %%%c\n", 'y');
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);

	i = printf("Expected output:    %s\n", "Holberton");
	j = _printf("Current output:     %s\n", "Holberton");
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);
	i = printf("Expected output:    %s$\n", "");
	j = _printf("Current output:     %s$\n", "");
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);
	i = printf("Expected output:    %s\n", "hello, world");
	j = _printf("Current output:     %s\n", "hello, world");
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);
	i = printf("Expected output:    %s$\n", NULL);
	j = _printf("Current output:     %s$\n", NULL);
	printf("Expected length:    %i\n", i);
	printf("Current length:     %i\n", j);
	i = printf("Expected output:    %sschool\n", "Holberton");
	j = _printf("Current output:     %sschool\n", "Holberton");
	printf("Expected length:    %i\n", i);
	printf("Current length:     %i\n", j);

	i = printf("Expected output:    %%\n");
	j = _printf("Current output:     %%\n");
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);
	i = printf("Expected output:    %%%%\n");
	j = _printf("Current output:     %%%%\n");
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);
	printf("Expected output:    ");
	i = printf("%");
	printf("\n");
	printf("Current output:     ");
	j = _printf("%");
	printf("\n");
	printf("Expected length:    %d\n", i);
	printf("Current length:     %d\n", j);
	return (0);
}
