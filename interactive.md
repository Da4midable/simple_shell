#include "main.h"

/**
* main - main function to be used to compile program
* Return: zero
*/

int process_interactive()
{
	char *command = NULL, **argv, *command_cpy = NULL, *tokenized = NULL, *env_tok = NULL, **env_var, *var_name1, *var_name2;
	char *delim = " \n", buffer[BUFF_SIZE], *new_dir = NULL, *goback_dir = NULL, *env_tok2 = NULL, *cwd, *old = "OLDPWD";
	char *cmd = "/bin/ls";
	size_t buff_size = 0;
	ssize_t n_read = 0;
	int i = 0, fd = STDIN_FILENO, rec_a, argc = 0;

	
	signal(SIGINT, sigint_handler);

	while (1)
	{
             
        n_read = get_line(&command, &buff_size, stdin);
	

		if (!command)
		{
			free(command);
			command = NULL;
			return (-1);
		}

		command[n_read - 1] = '\0';
		if (n_read == -1)
		{
			free(command);
			command = NULL;
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


		while(tokenized)
		{
			tokenized = _strtok(NULL, delim);
			argc++;
		}

		argv = malloc(sizeof(char *) * (argc + 2));
		free(command_cpy);
		command_cpy = NULL;
		
		command_cpy = _strdup(command);

		free(command);
		command = NULL;
		tokenized = _strtok(command_cpy, delim);
		
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

		
		if (_strcmp(argv[0], "exit") == 0)
		{
			if ((argc > 1))
			{
			
				rec_a = _atoi(argv[1]);
				if (rec_a >= 0 && _isdigit(argv[1]))
				{
					free(command_cpy);
					free(argv);
					exit(rec_a);
				}
				_dprintf(2, "./hsh: 1: %s: Illegal number\n", argc, argv[1]);
				exit(2);
			}

			if (argc == 1)
			{
				free(command_cpy);
				free(argv);
				exit(0);
			}
			else
			{
				
				free(command_cpy);
				free(argv);
				exit(2);
				
			}
		
		}

		else if (_strcmp(*argv, "setenv") == 0)
		{
            if (argc > 1)
			{
				argv++;
				var_name1 = *argv;
				argv++;
				var_name2 = *argv;

				_setenv(var_name1, var_name2, environ);
				
			}

			else 
			{
				free(argv[0]);
				free(argv);
			}

        }


		else if (_strcmp(argv[0], "unsetenv") == 0)
		{
			if (argc == 2 && argv[1])
			{
				_unsetenv(argv[1]);
			}
				
				free(command_cpy);
				free(argv);

		}

		else if (_strcmp(argv[0], "cd") == 0)
		{
			if (!(argv[1]))
			{
				new_dir = _getenv("HOME");
				env_tok = _strtok(new_dir, "=");
				argv[1] = env_tok;
				argv[2] = _strtok(NULL, "=");
				if (argv[1] && argv[2])
				{
					cwd = getcwd(buffer, BUFF_SIZE);
					if (cwd)
					{
						_setenv(old, buffer, environ);
					}
				}
				chdir(argv[2]);
				free(env_tok);
				free(argv);
			}

			else if (_strcmp(argv[1], "-") == 0)
			{
				goback_dir = _getenv("OLDPWD");
				env_tok2 = _strtok(goback_dir, "=");
				argv[1] = env_tok2;
				argv[2] = _strtok(NULL, "=");
				getcwd(buffer, BUFF_SIZE);
				_setenv("OLDPWD", buffer, environ);
				chdir(argv[2]);
				free(env_tok2);
				free(argv);
				
			}

			else if (argv[1])
			{

				getcwd(buffer, BUFF_SIZE);
				_setenv("OLDPWD", buffer, environ);
				chdir(argv[1]);
				
			}

			else
			{
				;
			}
	
		}


		else if (_strcmp(command_cpy, "env") == 0)
		{

			for (env_var = environ; *env_var; env_var++)
			{
       			_dprintf(1,"%s\n", *env_var);
    		}
			free(argv);
		}

		else 
		{
			(void)(cmd);
			(void)(fd);
			fork_exec(argv);
		}
			free(command_cpy);	
	}
}