#include "main.h"

/**
* *_strcat - concatenate source to destination
* @src: first pointer
* @dest: second pointer
* Return: Always 0.
*/

char *_strcat(char *dest, const char *src)
{
	int i = 0, j = 0, n = 0;


	while (dest[i++])
	{
		j++;
	}

	for (i = 0; src[i] && i >= n; i++)
	{
		dest[j++] = src[i];
	}

return (dest);
}
