#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main() {
	pid_t child1, child2;
	int parent_pid = getpid();
        child1 = fork();
        int i, j;
        if(child1 < 0) {
                perror("Fork failed.\n");
                return 1;
        } else if(child1 == 0) {
                for(i=1;i<=10;i++) {
                        printf("Parent PID : %d, Process PID : %d, Iteration no: %d\n", parent_pid, getpid(), i);
                        sleep(2);
                }
        } else {
                child2 = fork();
                if(child2 < 0) {
                        perror("Fork failed.\n");
                } else if(child2 == 0 ) {
                        for(j=1;j<=10;j++) {
                                printf("Parent PID : %d, Process PID : %d, Iteration no: %d\n", parent_pid, getpid(), j);
                                sleep(1);
                        }
                }

        }
	wait(NULL);
        wait(NULL);
        return 0;
}


