#include "main.h"

/**
 * is_printable - Evaluates if char is printable
 * @a: Char evaluate
 *
 * Return: 1 if a is printable, 0 otherwise
 */
int is_printable(char a)
{
	if (a >= 32 && a < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars
 * @z: Index to start appending
 * @ascii_code: ASSCI CODE
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int z)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[z++] = '\\';
	buffer[z++] = 'x';

	buffer[z++] = map_to[ascii_code / 16];
	buffer[z] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @a: Char to be evaluated
 *
 * Return: 1 if a is a digit, 0 otherwise
 */
int is_digit(char a)
{
	if (a >= '0' && a <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - a number to the specified size
 * @num: Number cast
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number cast
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
