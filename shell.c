#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(void)
{
    char *buff;
    char *buffarray[] = {buff, NULL};
    char *envp[] = {"PATH=/bin", NULL};
    size_t buffsize = 1024;
    pid_t child_pid;
    int status, i;
    
    if((buff = malloc(sizeof(char) * buffsize) ) == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    for(i = 0; ; i++)
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }
        if (child_pid == 0)
        {
            printf("nigga$ ");
            getline(&buff, &buffsize, stdin);
            execve(buffarray[0], buffarray, envp);
        }
        else
            wait(&status);
    }
return 0;
}
  
    
