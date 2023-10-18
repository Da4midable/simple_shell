#include "main.h"

int _dprintf(int fd, const char *format, ...)
{
    va_list args;
    char *str;
    const char *c = format;
    int written = 0, num, temp, num_digits, i, len;
    char buf[12];

    va_start(args, format);

    while (*c != '\0')
    {
        if (*c == '%')
        {
            switch (*(c + 1))
            {
                case 'd':
                {
                    num = va_arg(args, int);

                   
                    if (num < 0)
                    {
                        written += write(fd, "-", 1);
                        num = -num;
                    }

                    temp = num;
                    num_digits = 1;
                    while (temp >= 10)
                    {
                        temp /= 10;
                        num_digits++;
                    }

                    buf[num_digits] = buf[num_digits + 1];
                    buf[num_digits] = '\0';

                    for (i = num_digits - 1; i >= 0; i--)
                    {
                        buf[i] = '0' + (num % 10);
                        num /= 10;
                    }

                    written += write(fd, buf, num_digits);
                    c++;
                    break;
                }
                case 's':
                {
                    str = va_arg(args, char*);
                    len = 0;
                    while (str[len] != '\0')
                    {
                        len++;
                    }
                    written += write(fd, str, len);
                    c++;
                    break;
                }

                default:
                    written += write(fd, c, 1);
                    break;
            }
        }
        else
        {
            written += write(fd, c, 1);
        }

        c++;
    }

    va_end(args);

    return written;
}
