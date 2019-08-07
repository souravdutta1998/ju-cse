#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#define S1 "/sem1"
#define S2 "/sem2"


void display(unsigned int  t,sem_t* p2_sw, sem_t* p2_sp ){
	int i;
	for(i = 1; i <= 10; i++){
		sem_wait(p2_sw);
		printf("Parent: %d, Process: %d, Itr: %d\n",getppid(),getpid(),i);
		sem_post(p2_sp);
		sleep(t);
	}
}

int main(){
	sem_t *p2_sem1, *p2_sem2;
	pid_t pid1 = -1, pid2 = -1;
	if((p2_sem1 = sem_open(S1,O_CREAT,0660,1)) == SEM_FAILED
		|| (p2_sem2 = sem_open(S2,O_CREAT,0060,0)) == SEM_FAILED){
		perror("sem_open() Failed");
	}
	if((pid1 = fork()) < 0){
		perror("fork() Failed!");
		exit(1);
	}
	else if(pid1 == 0){
		// process X
		display(3,p2_sem1,p2_sem2);
	}
	else{
		if((pid2 = fork()) < 0){
			perror("fork() Failed!");
			exit(1);
		}
		else if(pid2 == 0){
			// process Y
			display(2,p2_sem2,p2_sem1);
		}
		else{
			// parent
			wait(NULL);
			wait(NULL);
			if(sem_unlink(S1) == -1 || sem_unlink(S2) == -1){
				perror("sem_unlink() Failed");
			}
		}
	}
	return 0;
}
