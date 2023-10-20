#include "main.h"


/**
 * _setenv - sets argv[1] to argv[2] in environment
 * @name: argv[1]
 * @value: argv[1]
 * @env: environment variable
 * Return: 0
 */

int _setenv(const char *name, const char *value, char **env)
{
	char *env_var;
	size_t len = _strlen(name) + _strlen(value) + 2;

	env_var = malloc(len);
	if (!env_var)
	{
		return (-1);
	}

	_strcpy(env_var, name);
	_strcat(env_var, "=");
	_strcat(env_var, value);

	if (_putenv(env_var, env) != 0)
	{
		free(env_var);
		return (-1);
	}

	return (0);
}
