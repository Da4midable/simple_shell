#include "main.h"

/**
* main - main function to be used to compile program
* Return: zero
*/


        

int main()
{
	char *command = NULL, *command_cpy = NULL, *command_path = NULL, **argv = NULL, *tokenized = NULL, *env_tok = NULL;
	char *delim = " ", buffer[BUFF_SIZE], *new_dir = NULL, *goback_dir = NULL, *env_tok2 = NULL, *cmd;
	size_t buff_size = 0;
	ssize_t n_read = 0;
	int i = 0, argc = 0, fd = STDIN_FILENO;

	
	
	signal(SIGINT, sigint_handler);


	

while (1)
{
		
		n_read = get_line(&command, &buff_size, stdin);
		command[n_read - 1] = '\0';

		if (n_read == -1)
		{
			free(command);
			return (-1);
		}

		if (!n_read)
		{
			free(command);
			return (-1);
		}

		command_cpy = _strdup(command);

		if (command_cpy == NULL)
		{
			free(command_cpy);
			free(command);
			return (-1);
		}



		tokenized = _strtok(command_cpy, delim);

		argc = 0;

		while(tokenized)
		{
			tokenized = _strtok(NULL, delim);
			argc++;
		}
		argv = malloc(sizeof(char *) * (argc + 1));
		free(command_cpy);
		command_cpy = NULL;
		
		command_cpy = _strdup(command);

		tokenized = _strtok(command_cpy, delim);
		free(command);
		command = NULL;		

		if (argv == NULL)
		{
			free(argv);
            free(command_cpy);
            free(command);
		}


		i = 0;
		while (tokenized)
		{
			argv[i] = tokenized;
			tokenized = _strtok(NULL, delim);
			i++;
		}
		
			argv[i] = '\0';
		
		
		command_path = locate(argv[0]);

		if (command_path)
		{

			argv[0] = command_path;

			if (fork() == 0)
			{

				execve (argv[0], argv, environ);
				if (execve (argv[0], argv, environ) == -1)
					if (execve (argv[0], argv, environ) == -1) {
						free(argv);
						free(command_cpy);
						free(command);
					}
                    if (errno == EACCES) {
                        perror("Error:");
						free(command_path);
                        exit(126);
					}
                       perror("Error:");
						free(command_path);
                        exit(127);
        
                }
			

			else
			{

				wait(NULL);
				free(argv[0]);
				argv[0] = NULL;
				free(argv);
				argv = NULL;
				if (!isatty(fd))
				{
					sigint_handler(0);
				}
			}
		}
		
		else if (_strcmp(argv[0], "exit") == 0)
		{
			if (!(argv[1]))
			{
				exit(0);
			}
			else if (_isdigit(argv[1]))
				exit(_atoi(argv[1]));
		}

		else if (_strcmp(argv[0], "export") == 0)
		{
   			env_tok = _strtok(command_cpy, " ");
			env_tok = _strtok(NULL, "=");
			argv[1] = env_tok;
			env_tok = _strtok(NULL, "=");
			argv[2] = env_tok;

			setenv(argv[1], argv[2], 1);
		}

		else if (_strcmp(argv[0], "unset") == 0)
		{
    		env_tok = _strtok(command, " ");
    		env_tok = _strtok(NULL, " ");
    		unsetenv(env_tok);
		}


		else if (_strcmp(argv[0], "cd") == 0)
		{
			if (!(argv[1]))
			{
				new_dir = _getenv("HOME");
				env_tok = _strtok(new_dir, "=");
				argv[1] = env_tok;
				argv[2] = _strtok(NULL, "=");
				getcwd(buffer, BUFF_SIZE);
				setenv("OLDPWD", buffer, 1);
				chdir(argv[2]);
				printf("%s\n", command_cpy);
			}

			else if (_strcmp(argv[1], "-") == 0)
			{
				goback_dir = _getenv("OLDPWD");
				env_tok2 = _strtok(goback_dir, "=");
				argv[1] = env_tok2;
				argv[2] = _strtok(NULL, "=");
				getcwd(buffer, BUFF_SIZE);
				setenv("OLDPWD", buffer, 1);
				chdir(argv[2]);
				printf("%s\n", command_cpy);
			}

			else
			{

				getcwd(buffer, BUFF_SIZE);
				setenv("OLDPWD", buffer, 1);
				chdir(argv[1]);

			}
				free(new_dir);
				new_dir = NULL;
				free(goback_dir);
				goback_dir = NULL;
		}

		else
		{	
			
			;
		
		}
			
}
	return (0);
}
