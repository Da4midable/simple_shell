#include "main.h"

/**
 * fork_exec - Forks and executes a given command.
 * @argv: A double pointer to an array of strings containing command
 *
 * Return: Upon success, returns 0. On failure, returns an error code.
 */

int fork_exec(char **argv)
{
	char *command_path, *take_ovlp, *cmd = "ls";
	int status, exit_status, count = 0, i = 0;
	pid_t child_pid;

	take_ovlp = _strstr(*argv, cmd);
	while (take_ovlp)
	{
		count++;
		take_ovlp += _strlen(cmd);
		take_ovlp = _strstr(take_ovlp, cmd);
	}
	if (_strstr(*argv, cmd))
	{
		for (i = 0; i < count; i++)
		{
			child_pid = fork();
			if (child_pid == 0)
			{
				command_path = locate(argv[0]);
				execve(command_path, argv, environ);
				return (0);
				if (execve(command_path, argv, environ) == -1)
				{
					if (errno == EACCES)
					{
						exit(126);
					}
					exit(127);
				}
			}
			else
			{
				wait(&status);
				if (WIFEXITED(status))
					(void)(exit_status);
			}
		}
		return (0);
	}

	else
	{
		;
	}
		return (0);
}
