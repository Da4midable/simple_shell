#include "main.h"

/**
* main - main function to be used to compile program
* Return: zero
*/

int main(int argc, char** argv, char **env)
{
	char *command = NULL, *command_cpy = NULL, *command_path = NULL, *tokenized = NULL, *env_tok = NULL, **env_var;
	char *delim = " \n", buffer[BUFF_SIZE], *new_dir = NULL, *goback_dir = NULL, *env_tok2 = NULL;
	size_t buff_size = 0;
	ssize_t n_read = 0;
	int i = 0, fd = STDIN_FILENO, rec_a;

	
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

				_dprintf(2, "./hsh: %d: %s: Illegal number: %s\n", argc, argv[1]);
				free(command_cpy);
				free(argv[1]);
				free(argv);
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
			}
		
		}

		else if (_strcmp(argv[0], "setenv") == 0)
		{
            if (argc != 3) 
			{
                _dprintf(2, "Usage: %s %s %s\n", argv[0], argv[1], argv[2]);
            } 
			else 
			{
                _setenv(argv[1], argv[2]);
            }
				return(0);
        }


		else if (_strcmp(argv[0], "unsetenv") == 0)
		{
  			if (argc != 2)
   			{
       			_dprintf(2, "Usage: %s %s\n", argv[0], argv[1]);
    		}

    		else
    		{
       			size_t var_name_len = strlen(argv[1]);
        		int i;
        		for (i = 0; environ[i] != NULL; i++)
        		{
            		if (set_strncmp(environ[i], argv[1], var_name_len) == 0 && environ[i][var_name_len] == '=')
            		{
                		while (environ[i] != NULL)
                		{
                   			environ[i] = environ[i + 1];
                    		i++;
                		}
                		break;
            		}
        		}
    		}
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
				_setenv("OLDPWD", buffer);
				chdir(argv[2]);
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

		else if (_strcmp(command_cpy, "env") == 0)
		{

			for (env_var = env; *env_var; env_var++)
			{
       			_dprintf(1,"%s\n", *env_var);
    		}
			free(command_cpy);
			free(argv);
			return(0);
		}

		else if (fork() == 0)
		{
			command_path = locate(argv[0]);

			execve (command_path, argv, NULL);
			if (execve (argv[0], argv, NULL) == -1)
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
