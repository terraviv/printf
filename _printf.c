#include "main.h"
void print_buffer(char my_array[], int *rel_var1);
/**
 * print_buffer - f1
 * @my_array: p1.
 * @rel_var1: p2.
 */
void print_buffer(char my_array[], int *rel_var1)
{
	if (*rel_var1 > 0)
		write(1, &my_array[0], *rel_var1);
	*rel_var1 = 0;
}
/**
 * _printf - f1
 * @format: p1.
 * Return: something.
 */
int _printf(const char *format, ...)
{
	int j, flags, manapted = 0, mypted = 0;
	int with, vice, darb, bd = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[bd++] = format[j];
			if (bd == BUFF_SIZE)
				print_buffer(buffer, &bd);
			mypted++;
		}
		else
		{
			print_buffer(buffer, &bd);
			flags = get_flags(format, &j);
			with = get_width(format, &j, list);
			vice = get_precision(format, &j, list);
			darb = get_size(format, &j);
			++j;
			manapted = handle_print(format, &j, list, buffer,
				flags, with, vice, darb);
			if (manapted == -1)
				return (-1);
			mypted += manapted;
		}
	}

	print_buffer(buffer, &bd);

	va_end(list);

	return (mypted);
}

