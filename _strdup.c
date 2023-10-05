#include "main.h"

/**
* _strdup - duplicates string
* @str: string to be duplicated
* Return: dup
*/

char *_strdup(const char *str)
{
	size_t i = 0, len = 0;
	char *dup;

	while (str[i])
	{
		i++;

		len++;
	}

	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	i = 0;

	while (i <= len)
	{
		dup[i] = str[i];
		i++;
	}

	return (dup);
}
