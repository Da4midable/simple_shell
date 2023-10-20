#include "main.h"



int main(int ac, char **av, char **env)
{
	char buffer[BUFF_SIZE], *env_tok = NULL, *var_name1, *var_name2;
	char *new_dir = NULL, *goback_dir = NULL, *env_tok2 = NULL, *cwd, *old = "OLDPWD";
	char *cmd = "/bin/ls";
	int i = 0, fd = STDIN_FILENO, rec_a;

	(void)(cmd);
		i = ac;
		(void)(i);


	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				exit(127);
			}
			return (EXIT_FAILURE);
		}
	}


	if (isatty(fd))
	{
		process_interactive();
	}

	else
	{
		if ((_strcmp(av[1], "cd") == 0) && av[ac] != NULL)
		{
			av[0] = "./hsh";

			printf("%s\n", av[1]);

				var_name1 = *av;
				av++;
				var_name2 = *av;
				if (var_name2)
				{
					new_dir = _getenv("HOME");
					env_tok = _strtok(new_dir, "=");
					av[2] = env_tok;
					av[3] = _strtok(NULL, "=");
					if (av[2] && av[3])
					{
						cwd = getcwd(buffer, BUFF_SIZE);
						if (cwd)
						{
							_setenv(old, buffer, environ);
						}
					}
					chdir(av[3]);
					free(env_tok);
				}

				else if (_strcmp(av[2], "-") == 0)
				{
					goback_dir = _getenv("OLDPWD");
					env_tok2 = _strtok(goback_dir, "=");
					av[2] = env_tok2;
					av[3] = _strtok(NULL, "=");
					getcwd(buffer, BUFF_SIZE);
					_setenv("OLDPWD", buffer, env);
					chdir(av[3]);
					free(env_tok2);
				}

				else if (av[2])
				{

					getcwd(buffer, BUFF_SIZE);
					_setenv("OLDPWD", buffer, environ);
					chdir(av[2]);
				}

				else
				{
					;
				}
			}

			else if (_strcmp(*av, "setenv") == 0)
			{
				if (ac > 2)
				{
					av++;
					var_name1 = *av;
					av++;
					var_name2 = *av;
					_setenv(var_name1, var_name2, environ);
				}

				else
				{
					;
				}
			}

			if (_strcmp(av[1], "exit") == 0)
			{
				if ((ac > 2))
				{

					rec_a = _atoi(av[2]);
					if (rec_a >= 0 && _isdigit(av[2]))
					{

						exit(rec_a);
					}
					_dprintf(2, "./hsh: 1: %s: Illegal number\n", ac, av[2]);
					exit(2);
				}

				if (ac == 1)
				{
					exit(0);
				}
				else
				{
					exit(2);
				}
			}
	}

		return (0);
}
