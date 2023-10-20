#include "main.h"


int main(int argc, char **argv) {
    char *cmd = "/bin/ls";
    char *com_cpy = "/bin/ls /bin/ls /bin/ls /bin/ls /bin/ls /bin/ls";
    char *args[] = {cmd, NULL};
    char *take_ovlp;
    int count = 0;

    take_ovlp = strstr(com_cpy, cmd);

    while (take_ovlp) {
        count++;

        take_ovlp += strlen(cmd);

        take_ovlp = strstr(take_ovlp, cmd);
    }

    
    
    for (int i = 0; i < count; i++)
    {
        if(fork() == 0)
        {
            execve(cmd, args, environ);
            return 0;
        }
         else
        {
            wait(NULL);
        }
    }

   
    return 0;
}




/*int main(int argc, char **argv) {
    char *cmd = "/bin/ls";
    char *args[] = {cmd, NULL};
    int count = 6;

    for (int i = 0; i < count; i++) {
        if(fork() == 0) {
            execve(cmd, args, environ);
            return 0; // This line is only reached if execve fails.
        }
        else {
            wait(NULL); // Wait for the child process to finish.
        }
    }

    return 0;
}*/
