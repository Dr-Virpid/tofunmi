#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 * Write a program that executes the command ls -l /tmp in 5 different child
 * processes. Each child should be created by the same process (the father).
 * Wait for a child to exit before creating a new child.
int main(void)
{
    int status, i;
    pid_t child_pid;
    char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
    char *envp[] = {"PATH=/bin", NULL}
    
    for(i = 0; i < 5; i++)
    {
        child_pid = fork();
        if (pid == -1)
        {
            perror("Error:");
            return (1);
        }
        if (child_pid == 0)
            execve(argv[0], argv, envp);
        else
            wait(&status);
    }
 return 0;
}
