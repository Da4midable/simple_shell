#include "main.h"

/**
* _strtok - tokenizes a string into other strings
* @str: the main string to be tokenized
* @delim: the delimiter to indicate the location of tokenization
* Return: token
*/

char *_strtok(char *str, const char *delim)
{
	static char *ptr;
	char *token;
	int i;

	if (str != NULL)
	{
		ptr = str;
	}

	if (ptr == NULL || *ptr == '\0')
	{
		return (NULL);
	}

	token = ptr;

	while (*ptr != '\0')
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*ptr == delim[i])
			{
				*ptr = '\0';
				ptr++;
				return (token);
			}
		}
		ptr++;
	}

	return (token);
}



