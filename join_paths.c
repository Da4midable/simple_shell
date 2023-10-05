#include "main.h"

/**
* join_paths - joins directories in path environment
* @sep: use to separate directories
* @path1: first path in environment to attach
* @path2: second path in environment to attach
* Return: joined paths
*/
char *join_paths(const char sep, const char *path1, const char *path2)
{
	size_t i = 0, k = 0, len = 0;
	char *joined = NULL;

	while (path1[i++] != '\0')
	{
		;
		len += i;
	}

	i = 0;

	while (path2[i++] != '\0')
	{
		;
		len += i;
	}
	len += 1;

	joined = malloc(sizeof(char *) * len);

	for (i = 0, k = 0; path1[k]; i++, k++)
	{
		joined[i] = path1[k];
	}
	joined[i++] = sep;

	for (k = 0; path2[k]; i++, k++)
	{
		joined[i] = path2[k];
	}
	joined[i] = '\0';

	return (joined);
}
