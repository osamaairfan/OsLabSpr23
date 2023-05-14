#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    if ((child_pid = fork()) == -1) { // fork error
        printf("fork error");
        exit(1);
    }

    else if (child_pid == 0) { // child process
        printf("Child process 1 created, starting new instance of the program...\n");
        char *args[] = {"./task2", NULL}; // name of the program to start
        execvp(args[0], args); // start new instance of the program
        printf("execvp failed"); // if execvp returns, it failed
        exit(1);
    } 

    else { // parent process
        printf("Parent process, starting infinite loop of creating child processes...\n");
        while ((child_pid = fork()) != -1) {
            if (child_pid == 0) { 
            // child process
                sleep(1);
                printf("Child process %d created, parent process %d\n", getpid(), getppid());
                sleep(1);
                printf("Child process %d terminated\n", getpid());
                exit(0);
            } 
            else { 
            // parent process
                sleep(0.2);
            }
        }
        printf("fork error"); // if fork returns -1, it failed
        exit(1);
    }

    return 0;
}
