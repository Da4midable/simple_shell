#include "main.h"

/**
* main - main function to be used to compile program
* Return: zero
*/

int main(int argc, char** argv, char **env)
{
	char *command = NULL, *command_cpy = NULL, *command_path = NULL, *tokenized = NULL, *env_tok = NULL, **env_var, *var_name, *var_value;
	char *delim = " \n", buffer[BUFF_SIZE], *new_dir = NULL, *goback_dir = NULL, *env_tok2 = NULL, *cwd, *old = "OLDPWD";
	size_t buff_size = 0, var_name_len;
	ssize_t n_read = 0;
	int i = 0, fd = STDIN_FILENO, rec_a;

	
	signal(SIGINT, sigint_handler);

	while (1)
	{

        if (isatty(fd))
		{
        
            n_read = get_line(&command, &buff_size, stdin);
        } 
		else 
		{
        
            n_read = read(STDIN_FILENO, buffer, sizeof(buffer));
            if (n_read == -1)
			{
                perror("read");
                exit(EXIT_FAILURE);
            }
            command = strndup(buffer, n_read);
        }

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
		

		argc = 0;

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

		else if (_strcmp(argv[0], "setenv") == 0)
		{
            if (argc > 2 && argv[1] && argv[2])
			{	
				var_name_len = strlen(argv[1]);
                var_name = malloc(var_name_len + 1);
                var_value = malloc(strlen(argv[2]) + 1);

                custom_concat(var_name, argv[1], "=");
                custom_concat(var_name, var_name, argv[2]);

                for (i = 0; env[i] != NULL; i++) {
                    if (strncmp(env[i], argv[1], var_name_len) == 0) {
                        free(env[i]);
                        env[i] = var_name;
                        env[i + 1] = var_value;
                        break;
                    }
                }

                if (env[i] == NULL) {
                    env[i] = var_name;
                    env[i + 1] = var_value;
                    env[i + 2] = NULL;
                }
			}
				free(command_cpy);
				free(argv);
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
						_setenv(old, buffer);
					}
				}
				chdir(argv[2]);
				free(env_tok);
				free(command_cpy);
				free(argv);
			}

			else if (_strcmp(argv[1], "-") == 0)
			{
				goback_dir = _getenv("OLDPWD");
				env_tok2 = _strtok(goback_dir, "=");
				argv[1] = env_tok2;
				argv[2] = _strtok(NULL, "=");
				getcwd(buffer, BUFF_SIZE);
				_setenv("OLDPWD", buffer);
				chdir(argv[2]);
				free(env_tok2);
				free(command_cpy);
				free(argv);
				
			}

			else if (argv[1])
			{

				getcwd(buffer, BUFF_SIZE);
				_setenv("OLDPWD", buffer);
				chdir(argv[1]);
				
			}

			else
			{
				;
			}
	
		}

		else if (_strcmp(*argv, "#") == 0)
		{
			rep_com(*(argv));
		}

		else if (_strcmp(command_cpy, "env") == 0)
		{

			for (env_var = env; *env_var; env_var++)
			{
       			_dprintf(1,"%s\n", *env_var);
    		}
			free(command_cpy);
			free(argv);
		}

		else if (fork() == 0)
		{
			command_path = locate(argv[0]);

			execve (command_path, argv, environ);
			if (execve (argv[0], argv, environ) == -1)
			{
				if (errno == EACCES)
				exit(126);

				if (errno == ENOENT)
				{
					_dprintf(2, "./hsh: %d: %s: not found\n", argc, argv[0]);					
				}
        
			}
        
        }
			

		else
		{

			wait(NULL);
		
			if (!isatty(fd))
			{
				
				free(command_cpy);
				free(command_path);
				command_path = NULL;
				free(argv);
				argv = NULL;
				sigint_handler(0);
			
			}
			
                       
		}
				
}

	return (0);
}
