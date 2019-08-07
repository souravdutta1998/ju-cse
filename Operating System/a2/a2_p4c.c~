#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#define BUFFER_SIZE 1024

int main(){
	int fd[2];
	pid_t pid = -1;
	if(pipe(fd) == -1){
		perror("pipe() Failed");
		exit(1);
	}
	if((pid = fork()) < 0){
		perror("fork() Failed");
		exit(1);
	}
	else if(pid > 0){
		// writer process as the parent process
		char buffer[BUFFER_SIZE], dummy;
		close(fd[0]); // close reading end of pipe
		while(1){
			printf("Write in buffer:");
			scanf("%[^\n]s",buffer);
			scanf("%c",&dummy);
			write(fd[1],buffer,BUFFER_SIZE);
			sleep(2);
		}
		free(buffer);
		wait(NULL);// wait till end of reader process
		close(fd[1]);//close writing end of pipe
	}
	else if(pid == 0){
		//reader as the child process
		close(fd[1]); // close writing end of pipe
		char buffer[BUFFER_SIZE];
		while(1){
			if(read(fd[0],&buffer,BUFFER_SIZE) > 0){
				printf("Read from buffer : %s\n",buffer);
			}
		}
		close(fd[0]); // close reading end of pipe
		exit(0);
	}
	//return 0;
}

