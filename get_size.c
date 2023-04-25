#include "main.h"
/**
 * get_size - f1
 * @format: pa
 * @i: pa
 * Return: pa.
 */
int get_size(const char *format, int *i)
{
	int ak = *i + 1, bk = 0;

	if (format[ak] == 'l')
		bk = S_LONG;
	else if (format[ak] == 'h')
		bk = S_SHORT;
	if (bk == 0)
		*i = ak - 1;
	else
		*i = ak;
	return (bk);
}
