#include "main.h"
/**
* main - executes functions
* @argc: argument count
* @argv: argument vectors
* Return: 0
*/
int main(int argc, char **argv)
{
	char *command = "/usr/bin/gcc";
	char *args[] = {"gcc", "_atoi.c", "_getenv.c", "_isdigit.c", "_memcpy.c", "_putchar.c", "_sigint.c", "_strcmp.c", "_strdup.c", "_strlen.c", "_strstr.c", "_strtok.c", "getlines.c", "join_paths.c", "locate.c", "main.c", "realloc.c", "main.h", "-o", "program", NULL};
	

	if (fork() == 0)
	{
		execve(command, args, environ);
	}
	else
	{
		wait(NULL);

		rename("main.c", "main.txt");

		argv[0] = "./program";

		if (fork() == -1)
		{
			perror("fork");
			exit(0);
		}

		if (fork() == 0)
		{
			execve(argv[0], argv, environ);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
