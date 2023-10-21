#include "main.h"

/**
 * fork_exec - Forks and executes a given command.
 * @argv: A double pointer to an array of strings containing command
 * @ags: A single pointer containing one command
 * Return: Upon success, returns 0. On failure, returns an error code.
 */

int fork_exec(char **argv, char *ags)
{
	char *command_path, *take_ovlp;
	int status, exit_status, count = 0, fd;
	pid_t child_pid;

	take_ovlp = _strstr(*argv, ags);
	while (take_ovlp)
	{
		count++;
		take_ovlp += _strlen(ags);
		take_ovlp = _strstr(take_ovlp, ags);

	(void)(fd);
			child_pid = fork();
			if (child_pid == 0)
			{
				command_path = locate(ags);
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

				(void)(exit_status);
			}
	}
		return (0);
}
