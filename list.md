#include "main.h"
/**
* main - executes functions
* @argc: argument count
* @argv: argument vectors
* Return: 0
*/
int main(int argc, char **argv)
{
	char *command;
	int for_excomp = (_strcmp(argv[0], "exit") == 0);
	int for_envcomp = (_strcmp(argv[0], "env") == 0);


	if (argc > 1 || for_excomp || for_envcomp)
	{
		process_cmd(argc, argv);
	}

	if (argc == 1 && !for_excomp && !for_envcomp)
	{
		command = "/bin/ls";
		argv[0] = command;

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
