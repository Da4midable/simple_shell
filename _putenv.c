#include "main.h"


int _putenv(char *str)
{
    char *equals = _strchr(str, '=');
    int i;
    size_t len;

    if (equals == NULL || equals == str)
	{
        return -1;
    }


    len = equals - str;
    for (i = 0; environ[i] != NULL; i++)
    {
        if (set_strncmp(environ[i], str, len) == 0 && environ[i][len] == '=')
        {
            environ[i] = str;
            return 0;
        }
    }

   
    i = 0;
    while (environ[i] != NULL)
    {
        i++;
    }

    environ[i] = str;
    environ[i + 1] = NULL;

    return 0;
}
