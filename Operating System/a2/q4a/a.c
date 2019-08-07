#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#define BUFFER_SIZE 1024  
int main() 
{ 
    int fd; 
    char * myfifo = "/tmp/myfifo"; 
    mkfifo(myfifo, 0666); 
    char buffer[BUFFER_SIZE], dummy; 
    while (1){ 
        fd = open(myfifo, O_WRONLY); 
	printf("Enter the message you want to send: ");
	scanf("%[^\n]s",buffer);
	scanf("%c",&dummy); 
	write(fd, buffer, strlen(buffer)+1); 
        close(fd); 
    } 
    return 0; 
}
