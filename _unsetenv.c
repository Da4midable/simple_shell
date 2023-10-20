#include "main.h"

/**
 * _unsetenv - removes argv[1] from environment
 * @name: argv[1]
 * Return: void
 */

void _unsetenv(const char *name)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (set_strncmp(environ[i], name, _strlen(name)) == 0 && environ[i][_strlen(name)] == '=')
		{

			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			break;
		}
	}
}
