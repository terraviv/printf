#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int mcu = *i + 1;
	int precision = -1;

	if (format[mcu] != '.')
		return (precision);

	precision = 0;

	for (mcu += 1; format[mcu] != '\0'; mcu++)
	{
		if (is_digit(format[mcu]))
		{
			precision *= 10;
			precision += format[mcu] - '0';
		}
		else if (format[mcu] == '*')
		{
			mcu++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = mcu - 1;

	return (precision);
}
