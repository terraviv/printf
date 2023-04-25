#include "main.h"
/**
 * print_string - f3
 * @types: p1
 * @buffer: p2
 * @flags:  p3
 * @width: p4
 * @precision: p5
 * @size: p6
 * Return: something
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
char *poin = va_arg(types, char *);
int xcp, my_way = 0;

UNUSED(buffer);
UNUSED(flags);
UNUSED(size);
UNUSED(width);
UNUSED(precision);
	if (poin == NULL)
	{
		poin = "(null)";
if (precision >= 6)
poin = "      "; }
while (poin[my_way] != '\0')
my_way++;
if (precision >= 0 && precision < my_way)
my_way = precision;

	if (width > my_way)
	{
		if (flags & F_MINUS)
		{
			write(1, &poin[0], my_way);
xcp = width - my_way;
while (xcp > 0)
{
write(1, " ", 1);
xcp--; }
			return (width);
		}
		else
		{
			for (xcp = width - my_way; xcp > 0; xcp--)
				write(1, " ", 1);
			write(1, &poin[0], my_way);
			return (width);
		}
	}
	return (write(1, poin, my_way));
}
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
UNUSED(precision);
return (write(1, "%%", 1)); }
/**
 * print_int - f1
 * @types: p1
 * @buffer: p2
 * @flags:  p3
 * @width: p4
 * @precision: p5
 * @size: p6
 * Return: something
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
int var_pl = 0, x1 = BUFF_SIZE - 2;
long int x3 = va_arg(types, long int);
unsigned long int x2;

x3 = convert_size_number(x3, size);
if (x3 == 0)
buffer[x1--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
x2 = (unsigned long int)x3;
if (x3 < 0)
{
x2 = (unsigned long int)((-1) * x3);
var_pl = 1; }
while (x2 > 0)
{
buffer[x1--] = (x2 % 10) + '0';
x2 = x2 / 10; }
x1++;
return (write_number(var_pl, x1, buffer, flags, width, precision, size)); }
/**
 * print_binary - f4
 * @types: param
 * @buffer: param
 * @flags:  param
 * @width: param
 * @precision: param
 * @size: param
 * Return: something
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
int xt1;
unsigned int z1, mo_ncre, z2, ytl, a[32];
UNUSED(buffer);
UNUSED(flags);
UNUSED(size);
UNUSED(width);
UNUSED(precision);
z1 = 2147483648;
z2 = va_arg(types, unsigned int);
a[0] = z2 / z1;
for (mo_ncre = 1; mo_ncre < 32; mo_ncre++)
{
z1 = z1 / 2;
a[mo_ncre] = (z2 / z1) % 2; }
for (mo_ncre = 0, ytl = 0, xt1 = 0; mo_ncre < 32; mo_ncre++)
{
ytl += a[mo_ncre];
if (ytl || mo_ncre == 31)
{
char z = '0' + a[mo_ncre];
write(1, &z, 1);
xt1++; } }
return (xt1); }
/**
 * print_char - f5
 * @types: para
 * @buffer: para
 * @flags:  para
 * @width: para
 * @precision: para
 * @size: para
 * Return: something
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char varp = va_arg(types, int);

	return (handle_write_char(varp, buffer, flags, width, precision, size));
}
