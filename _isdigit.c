#include "main.h"

/**
* _isdigit - checks if dereferenced string is a digit
* @str: string to be checked
* Return: 0
*/

int _isdigit(char *str)
{
	while (*str)
	{
		if (*str > 47 && *str < 58)
		{
			return (1);
		}
	}
	return (0);
}
