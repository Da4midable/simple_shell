#include <stdio.h>
#include "main.h"

/**
* *_strcpy - calculates the length of a string
* @src: first pointer
* @dest: second pointer
* Return: Always 0.
*/

char *_strcpy(char *dest, const char *src)
{
	int a = 0;
	int b = 0;

	while (*(src + a) != '\0')
{
	a++;
}
	for (; b < a; b++)
{
	dest[b] = src[b];
}
	dest[a] = '\0';
	return (dest);

}
