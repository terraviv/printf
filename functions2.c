#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - f4
 * @types: pa
 * @buffer: pa
 * @flags:  pa
 * @width: pa
 * @precision: pa
 * @size: pa
 * Return: pa.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char v8 = 0, atg = ' ';
	char y4[] = "0123456789abcdef";
	int se1 = BUFF_SIZE - 2, s1 = 1, m4 = 2;
	unsigned long u1;
	void *b4 = va_arg(types, void *);

	UNUSED(size);
	UNUSED(width);
	if (b4 == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	u1 = (unsigned long)b4;
	while (u1 > 0)
	{
		buffer[se1--] = y4[u1 % 16];
		u1 = u1 / 16;
		m4++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		atg = '0';
	if (flags & F_PLUS)
		v8 = '+', m4++;
	else if (flags & F_SPACE)
		v8 = ' ', m4++;
	se1++;
	return (write_pointer(buffer, se1, m4,
		width, flags, atg, v8, s1));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - f3
 * @types: pb
 * @buffer: pb
 * @flags:  pb
 * @width: pb
 * @precision: pb
 * @size: pb
 * Return: pb
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

int k1 = 0;
int z1 = 0;
	char *y100 = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (y100 == NULL)
		return (write(1, "(null)", 6));

	while (y100[z1] != '\0')
	{
		if (is_printable(y100[z1]))
			buffer[z1 + k1] = y100[z1];
		else
			k1 += append_hexa_code(y100[z1], buffer, z1 + k1);

		z1++;
	}

	buffer[z1 + k1] = '\0';

	return (write(1, buffer, z1 + k1));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - f1.
 * @types: pa
 * @buffer: pa
 * @flags:  pa
 * @width: pa
 * @precision: pa
 * @size: pa
 * Return: pa
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *zk;
	int kz = 0;
int i;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	zk = va_arg(types, char *);
	if (zk == NULL)
	{
		UNUSED(precision);
		zk = ")Null(";
	}
	for (i = 0; zk[i]; i++)
		;
i = i - 1;
	while (i >= 0)
	{
		char z = zk[i];

		write(1, &z, 1);
		kz++;
i--; }
	return (kz);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - f5.
 * @types: pa
 * @buffer: pa
 * @flags:  pa
 * @width: pa
 * @precision: pa
 * @size: pa
 * Return: pa
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
char yz;
char *vk;
char bk[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
unsigned int ek, gk;
char ck[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
int kz = 0;

vk = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (vk == NULL)
vk = "(AHYY)";
for (ek = 0; vk[ek]; ek++)
{
gk = 0;
while (bk[gk])
{
if (bk[gk] == vk[ek])
{
yz = ck[gk];
write(1, &yz, 1);
kz++;
break;
}
gk++; }
if (!bk[gk])
{
yz = vk[ek];
write(1, &yz, 1);
kz++;
}
}
return (kz);
}
