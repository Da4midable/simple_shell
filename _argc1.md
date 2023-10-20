#include "main.h"

void execute_cmd(char *cmd, char **args, char **envp)
{
    execve((char*)cmd, args, envp);

    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) 
{
    const char *cmd = argv[1];
    char input[1024];
    int count = 0, i = 0;

    if (argc < 1) {
        fprintf(stderr, "Usage: %s <command_string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    while (fgets(input, sizeof(input), stdin) != NULL) {
        const char *start = input;

        while (1) {
            start = strstr(start, cmd);
            if (start == NULL)
                break;
            count++;
            start += strlen(cmd);
        }

        for (i = 0; i < count; i++) {
            execute_cmd((char*)cmd, argv, environ);
        }
    }

    return 0;
}
