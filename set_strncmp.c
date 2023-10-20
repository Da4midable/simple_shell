#include "main.h"

/**
 * set_strncmp - Compares at most the first 'n' characters of two strings.
 *
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * @n: Number of characters to compare.
 *
 * Return: Returns an integer greater than, equal to, or less than 0,
 * depending on the comparison result.
 */

int set_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}

	if (n == 0)
	{
		return (0);
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
