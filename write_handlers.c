#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - pa
 * @c: pa.
 * @buffer: pa
 * @flags:  pa
 * @width: pa
 * @precision: pa
 * @size: pa
 * Return: pa
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
int ak = 0;
char voice_y = ' ';
UNUSED(precision);
UNUSED(size);

if (flags & F_ZERO)
voice_y = '0';
buffer[ak++] = c;
buffer[ak] = '\0';

if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (ak = 0; ak < width - 1; ak++)
buffer[BUFF_SIZE - ak - 2] = voice_y;

if (flags & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - ak - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - ak - 1], width - 1) +
write(1, &buffer[0], 1));
}

return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - pb
 * @is_negative: pb
 * @ind: pb
 * @buffer: pb
 * @flags:  pb
 * @width: pb
 * @precision: pb
 * @size: pb
 * Return: pb
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	char voice_y = ' ', komb = 0;
	int va_u = BUFF_SIZE - ind - 1;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		voice_y = '0';
	if (is_negative)
		komb = '-';
	else if (flags & F_PLUS)
		komb = '+';
	else if (flags & F_SPACE)
		komb = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		va_u, voice_y, komb));
}

/**
 * write_num - pa
 * @ind: pa
 * @buffer: pa
 * @flags: pa
 * @width: pa
 * @prec: pa
 * @length: pa
 * @padd: pa
 * @extra_c: pa
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
int zj, amy = 1;

if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
return (0);
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' ';
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (zj = 1; zj < width - length + 1; zj++)
buffer[zj] = padd;
buffer[zj] = '\0';
if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], zj - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[1], zj - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--amy] = extra_c;
return (write(1, &buffer[amy], zj - amy) +
write(1, &buffer[ind], length - (1 - amy)));
}
}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - pa
 * @is_negative: pa
 * @ind: pa
 * @buffer: pa
 * @flags: pa
 * @width: pa
 * @precision: pa
 * @size: pa
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{

	int ytf = BUFF_SIZE - ind - 1, i = 0;
	char uptf = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < ytf)
		uptf = ' ';

	while (precision > ytf)
	{
		buffer[--ind] = '0';
		ytf++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		uptf = '0';

	if (width > ytf)
	{
		for (i = 0; i < width - ytf; i++)
			buffer[i] = uptf;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], ytf) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], ytf));
		}
	}

	return (write(1, &buffer[ind], ytf));
}

/**
 * write_pointer - pa
 * @buffer: pa
 * @ind: pa
 * @length: pa
 * @width: pa
 * @flags: pa
 * @padd: pa
 * @extra_c: pa
 * @padd_start: pa
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
int sq1;

if (width > length)
{
sq1 = 3;
while (sq1 < width - length + 3)
buffer[sq1] = padd;
sq1++;
buffer[sq1] = '\0';
if (flags & F_MINUS && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[3], sq1 - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], sq1 - 3) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], sq1 - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
