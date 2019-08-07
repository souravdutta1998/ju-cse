#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#define BUFFER_SIZE 1024
int main(){ 
	int fd1; 
	char * myfifo = "/tmp/myfifo"; 
	mkfifo(myfifo, 0666); 
	char str1[BUFFER_SIZE], str2[BUFFER_SIZE]; 
    	while (1){
	fd1 = open(myfifo,O_RDONLY); 
        read(fd1, str1, BUFFER_SIZE); 
	printf("%s\n", str1); 
        close(fd1); 
    } 
    return 0; 
} 
