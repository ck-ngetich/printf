long long int power(int base, int x)
{
	int output = 1;

	for (x; x > 0; x--)
	{
		output = output * base;
	}
	return (output);
}
