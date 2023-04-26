#include "main.h"

/**
 * get_precision - pa
 * @format: pa
 * @i: pa
 * @list: pa
 * Return: pa.
 */
int get_precision(const char *format, int *i, va_list list)
{
int ak = *i + 1;
int bk = -1;

if (format[ak] != '.')
return (bk);
bk = 0;
ak += 1;
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
