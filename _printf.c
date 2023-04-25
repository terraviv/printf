#include "main.h"
void print_buffer(char my_array[], int *rel_var1);
/**
 * print_buffer - f1
 * @my_array: p1.
 * @rel_var1: p2.
 */
void print_buffer(char my_array[], int *rel_var1)
{
	if (!(*rel_var1 > 0))
		*rel_var1 = 0;
	write(1, &my_array[0], *rel_var1);
}
/**
 * _printf - f1
 * @format: p1.
 * Return: something.
 */
int _printf(const char *format, ...)
{
	int var_r1, i = 0, chs_var = 0, rel_var1 = 0;
va_list my_args;
	int buco_var, var2, var1, show_o = 0;
	char my_array[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(my_args, format);
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			my_array[rel_var1++] = format[i];
			if (rel_var1 == BUFF_SIZE)
				print_buffer(my_array, &rel_var1);
			chs_var++;
		}
		else
		{
			print_buffer(my_array, &rel_var1);
			var2 = get_width(format, &i, my_args);
			buco_var = get_flags(format, &i);
			var_r1 = get_precision(format, &i, my_args);
			var1 = get_size(format, &i);
			++i;
			show_o = handle_print(format, &i, my_args, my_array,
				buco_var, var2, var_r1, var1);
			if (show_o == -1)
				return (-1);
			chs_var += show_o;
		} i++;
	}
	print_buffer(my_array, &rel_var1);
	va_end(my_args);
	return (chs_var);
}

