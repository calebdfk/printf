#include "main.h"

/**
 * print_int - Print an integer
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Active flags (not used here)
 * @width: Width (not used here)
 * @precision: Precision (not used here)
 * @size: Size specifier (not used here)
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[index--] = (num % 10) + '0';
		num /= 10;
	}

	index++;

	return (write_number(is_negative, index, buffer, 0, 0, 0, 0));
}

