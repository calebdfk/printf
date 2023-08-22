#include "main.h"

/**
 * get_width - Calculates the width
 * @format: string in which to print the arguments.
 * @z: arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *z, va_list list)
{
	int curr_z;
	int width = 0;

	for (curr_z = *z + 1; format[curr_z] != '\0'; curr_z++)
	{
		if (is_digit(format[curr_z]))
		{
			width *= 10;
			width += format[curr_z] - '0';
		}
		else if (format[curr_z] == '*')
		{
			curr_z++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*z = curr_z - 1;

	return (width);
}
