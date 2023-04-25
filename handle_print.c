#include "main.h"
/**
 * handle_print - pc
 * @fmt: pc
 * @list: pc
 * @ind: pc
 * @buffer: pc
 * @flags: pc
 * @width: pc
 * @precision: pc
 * @size: pc
 * Return: pc
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
int bk = -1;
int ak = 0;
int ck;
fmt_t fmt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
ck = 0;
while (fmt_types[ck].fmt != '\0')
if (fmt[*ind] == fmt_types[ck].fmt)
return (fmt_types[ck].fn(list, buffer, flags, width, precision, size));
ck++;

if (fmt_types[ck].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
ak += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
ak += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
ak += write(1, &fmt[*ind], 1);
return (ak);
}
return (bk);
}
