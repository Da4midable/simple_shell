#include "main.h"

/**
* _getenv - searches for and return name from environment
* @name: name argument to be searched for in environment
* Return: NULL
*/

char *_getenv(const char *name)
{
	size_t i = 0, k = 0;
	char *env_var = NULL;
	char *dup_env = NULL;

	while (environ[i])
	{
		env_var = environ[i];

		while (env_var[k] == name[k] && env_var[k] != '=' && env_var[k] && name[k])
		{
			k++;
		}
		if (name[k] == '\0')
		{
			dup_env = _strdup(env_var);
			return (dup_env);
			free(dup_env);
		}

		i++;
	}

	return (NULL);
}
