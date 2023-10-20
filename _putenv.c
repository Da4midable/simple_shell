#include "main.h"

/**
* _putenv - writes to environment
* @str: string to be appended
* @env: enviroment variable
* Return: NULL
*/

int _putenv(char *str, char **env)
{
	char *equals = _strchr(str, '=');
	int i;
	size_t len;

	if (equals == NULL || equals == str)
	{
		return (-1);
	}


	len = equals - str;
	for (i = 0; env[i] != NULL; i++)
	{
		if (set_strncmp(env[i], str, len) == 0 && env[i][len] == '=')
		{
			env[i] = str;
			return (0);
		}
	}


	i = 0;
	while (env[i] != NULL)
	{
		i++;
	}

	env[i] = str;
	env[i + 1] = NULL;

	return (0);
}
