#include "main.h"

/**
* *_strchr - searches a specific character
* @s: pointer
* @c: character to be searched
* Return: Always null.
*/

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] > '\0'; i++)
{
	if (s[i] == c)

	return (s + i);

}
	return ('\0');
}
