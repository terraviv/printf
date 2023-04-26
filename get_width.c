#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int mcu;
	int width = 0;

	for (mcu = *i + 1; format[mcu] != '\0'; mcu++)
	{
		if (is_digit(format[mcu]))
		{
			width *= 10;
			width += format[mcu] - '0';
		}
		else if (format[mcu] == '*')
		{
			mcu++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = mcu - 1;

	return (width);
}
