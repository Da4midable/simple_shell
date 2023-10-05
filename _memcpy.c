#include "main.h"

/**
* *_memcpy - transforms all lower to upper
* @dest: destination of copies bytes
* @src: source to copy bytes from
* @n: default number of bytes in source memory area
* Return: Always s.
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
{
	dest[i] = src[i];
	i++;
}
	return (dest);
}
