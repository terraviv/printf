#include "main.h"
/**
 * get_width - pb
 * @format: pb
 * @i: pb
 * @list: pb
 * Return: pb.
 */
int get_width(const char *format, int *i, va_list list)
{
int ak;
int bk = 0;

ak = *i + 1;
while (format[ak] != '\0')
{
if (is_digit(format[ak]))
{
bk *= 10;
bk += format[ak] - '0';
}
else if (format[ak] == '*')
{
ak++;
bk = va_arg(list, int);
break;
}
else
break;
ak++;
}

*i = ak - 1;
return (bk);
}
