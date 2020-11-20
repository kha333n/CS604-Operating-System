#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int pid, status;
    pid = fork();
    printf("%d\n",pid);
    if(pid == -1) {
        printf("fork failed\n");
        exit(1);
    }
    if(pid == 0) { /* Child */
        printf("Child created\n");
        pause();
        if (execlp("/bin/ls", "ls", NULL)< 0) {
            printf("exec failed\n");
            pause();
            exit(1);
        }
    }
    else { /* Parent */
        wait(&status);
        printf("Well done kid!\n");
        pause();
        exit(0);
    }
}