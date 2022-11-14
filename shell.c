#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int __attribute__((__unused__)) argc, char __attribute__((__unused__)) **argv, char *envp[])
{
    char *buffarray[] = {NULL, NULL};
    char *tok;
    size_t num;
    pid_t child_pid;
    int status;
    
    while (1)
    {
        printf("nigga$ ");
	num = getline(&tok, &num, stdin);
	buffarray[0] = tok;	
	tok = strtok(buffarray[0], " \n\r\t");
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }
        if (child_pid == 0)
        {
            execve(tok, buffarray, envp);
            printf("%ld\n", num);
        }
        else
            wait(&status);
    }
return 0;
}
  
