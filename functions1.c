#include "main.h"


/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - f3
 * @types: pa
 * @buffer: pa
 * @flags:  pa
 * @width: pa
 * @precision: pa
 * @size: pa
 * Return: pa
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	unsigned long int z1 = va_arg(types, unsigned long int);
	int c1 = BUFF_SIZE - 2;
	unsigned long int z2 = z1;

	UNUSED(width);
	z1 = convert_size_unsgnd(z1, size);
	if (z1 == 0)
		buffer[c1--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (z1 > 0)
	{
		buffer[c1--] = (z1 % 8) + '0';
		z1 =  z1 / 8;
	}

	if (flags & F_HASH && z2 != 0)
		buffer[c1--] = '0';

	c1++;

	return (write_unsgnd(0, c1, buffer, flags, width, precision, size));
}
/**
 * print_unsigned - f5
 * @types: p1
 * @buffer: p2
 * @flags:  p3
 * @width: p4
 * @precision: p5
 * @size: p6
 * Return: so.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a1 = BUFF_SIZE - 2;
	unsigned long int v1 = va_arg(types, unsigned long int);

	v1 = convert_size_unsgnd(v1, size);
	if (v1 == 0)
		buffer[a1--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (v1 > 0)
	{
		buffer[a1--] = (v1 % 10) + '0';
		v1 = v1 / 10;
	}
	a1++;
	return (write_unsgnd(0, a1, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - f1
 * @types: pa
 * @buffer: pa
 * @flags:  pa
 * @width: pa
 * @precision: pa
 * @size: pa
 * Return: pa
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/**
 * print_hexa - f4
 * @types: pc
 * @map_to: pc
 * @buffer: pc
 * @flags:  pc
 * @flag_ch: pc
 * @width: pc
 * @precision: pc
 * @size: pc
 * @size: pc
 * Return: pc
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	unsigned long int y1 = va_arg(types, unsigned long int);
	unsigned long int z2 = y1;
	int d1 = BUFF_SIZE - 2;

	UNUSED(width);
	y1 = convert_size_unsgnd(y1, size);
	if (y1 == 0)
		buffer[d1--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (y1 > 0)
	{
		buffer[d1--] = map_to[y1 % 16];
		y1 = y1 / 16;
	}
	if (flags & F_HASH && z2 != 0)
	{
		buffer[d1--] = flag_ch;
		buffer[d1--] = '0';
	}
	d1++;
	return (write_unsgnd(0, d1, buffer, flags, width, precision, size));
}
/**
 * print_hexa_upper - f2
 * @types: pb
 * @buffer: pb
 * @flags:  pb
 * @width: pb
 * @precision: pb
 * @size: pb
 * Return: pb
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
