#include "main.h"

/**
* _strlen - counts string length
* @str: string whose length is to be determined
* Return: len
*/

size_t _strlen(const char *str)
{
	int i = 0;
	size_t len = 0;

	while (str[i++])
	{
		len++;
	}

	return (len);
}
