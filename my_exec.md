#include "main.h"

/**
* _strcmp - checks if two strings match
* @argc: argument count
* @argv: second of the strings to be compared
* Return: difference in value of dereferenced strigns
*/

int main(int argc, char **argv)
{

    pid_t pid;

    while (1)
    {pid = fork();

	argv[0] = "./program";

    if (argc == 1)
    {
        _putchar(*argv[0]);
    }
  

    if (pid == -1) {
        perror("fork");
        exit(0);
    }

    if (pid == 0)
    {
        execve(argv[0], argv, environ);
        perror("execve");
        exit(0);
    }

    else
    {

            wait(NULL);
    }
    }
    return 0;
}
