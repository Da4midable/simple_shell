#include "main.h"

/**
 * custom_concat - Concatenates two strings and stores the result in 'dest'.
 * @dest: Pointer to the destination buffer.
 * @str1: Pointer to the first source string.
 * @str2: Pointer to the second source string.
 *
 * This function concatenates the strings 'str1' and 'str2' and stores the
 * result in the buffer pointed to by 'dest'. The 'dest' buffer must be large
 * enough to hold the concatenated string, including the null terminator.
 */

void custom_concat(char *dest, const char *str1, const char *str2)
{
	while (*str1)
	{
		*dest = *str1;
		str1++;
		dest++;
	}
	while (*str2)
	{
		*dest = *str2;
		str2++;
		dest++;
	}
	*dest = '\0';
}
