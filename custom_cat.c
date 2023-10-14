#include "main.h"

void custom_concat(char* dest, const char* str1, const char* str2)
{
    while (*str1) 
	{
        *dest = *str1;
        str1++;
        dest++;
    }
    while (*str2)
	{
        *dest = *str2;
        str2++;
        dest++;
    }
    *dest = '\0';
}