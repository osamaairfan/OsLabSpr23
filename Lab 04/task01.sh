#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int child_count = 0;
    pid_t child_pid;

    while ((child_pid = fork()) != -1) {
        if (child_pid == 0) { // child process
        	for (int i = 0; i < 15; i++) {
	        	sleep(1);
	            printf("Child process %d created, parent process %d\n", getpid(), getppid());
	            sleep(1);
	            printf("Child process %d terminated\n", getpid());
	            exit(0);
        	}
        } 
        else { // parent process
            child_count++;
            printf("Parent process, total children: %d\n", child_count);
            sleep(0.2);
        }        
    }

    printf("All children processes have terminated, parent process terminating\n");
    exit(0);
    return 0;
}
