#include "main.h"
/**
 * convert_size_unsgnd - pc
 * @num: pc
 * @size: pc
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
/**
 * append_hexa_code - pc
 * @buffer: pc
 * @i: pc
 * @ascii_code: pc
 * Return: pc
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char cbt[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = cbt[ascii_code / 16];
	buffer[i] = cbt[ascii_code % 16];
	return (3);
}
/**
 * is_printable - pa
 * @c: pb.
 * Return: pb
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * is_digit - pc
 * @c: pc
 * Return: pc
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_number - pc
 * @num: pc
 * @size: pc
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
