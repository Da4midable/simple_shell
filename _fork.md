#include "main.h"


int fork_exec(char **argv)
{

	char *command_path;
	int status, exit_status;
	pid_t child_pid = fork();


	if (child_pid == -1)
	{
		perror("Error:");
		return (-1);
	}

	if (child_pid == 0)
	{
			command_path = locate(argv[0]);

			execve (command_path, argv, environ);
			if (execve (command_path, argv, environ) == -1)
			{
				if (errno == EACCES)
				{
					exit(126);
				}

				
			exit(1);        
			}
        
    }
			
	else
	{

		wait(&status);

			_dprintf(2, "./hsh: 1: %s: not found\n", argv[0]);
				exit(127);
			(void)(exit_status);
        
                       
	}
		return (0);
}
