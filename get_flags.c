#include "main.h"

/**
 * get_flags - f1
 * @format: pa
 * @i: pa
 * Return: pa
 */
int get_flags(const char *format, int *i)
{
int ek, ak;
int bk = 0;
const char ck[] = {'-', '+', '0', '#', ' ', '\0'};
const int dk[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

ak = *i + 1;
while (format[ak] != '\0')
{
for (ek = 0; ck[ek] != '\0'; ek++)
if (format[ak] == ck[ek])
{
bk |= dk[ek];
break;
}

if (ck[ek] == 0)
break;
ak++;
}

*i = ak - 1;
return (bk);
}
