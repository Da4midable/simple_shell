#include "main.h"

/**
* _strcmp - checks if two strings match
* @str1: first of the strings to be compared
* @str2: second of the strings to be compared
* Return: difference in value of dereferenced strigns
*/

int _strcmp(const char *str1, const char *str2)
{

	for (; *str1 == *str2; str1++, str2++)
	{
		if (*str1 == '\0')
		{
			return (0);
		}
	}

	return (*str1 - *str2);

}

