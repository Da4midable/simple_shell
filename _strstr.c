#include "main.h"

/**
* _strstr - checks if second string matches part/whole of first string
* @haystack: first of the strings to be compared
* @needle: second of the strings to be compared
* Return: NULL
*/

char *_strstr(char *haystack, char *needle)
{
	char *delim = " ";

	if (haystack == NULL || needle == NULL)
	{
		return (NULL);
	}

	while (haystack == delim)
	{
		haystack++;
	}

	for (; *haystack != '\0'; haystack++)
	{
		char *a = haystack;
		char *b = needle;

		while (*a == *b && *b != '\0')
		{
			a++;
			b++;
		}

		if (*b == '\0')
		{
			return (haystack);
		}
	}

	return (NULL);

}

