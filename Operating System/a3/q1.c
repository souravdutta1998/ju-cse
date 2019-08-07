#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct{
    int data;
    int readcount;
    int writecount;
}ReaderWriter;

int main()
{
    int rc,wc,i;

    ReaderWriter *rw;

    pid_t pid;

    printf("The number of readers -  ");
    scanf("%d", &rc);
    printf("The number of writers - ");
    scanf("%d", &wc);

    sem_t *mutex3,*r,*mutex1,*wrt,*mutex2;
    sem_unlink("/semaphore1");
    mutex3 = sem_open("/semaphore1", O_CREAT,  0644, 1);
    sem_unlink("/semaphore2");
    mutex2 = sem_open("/semaphore2", O_CREAT,  0644, 1);
    sem_unlink("/semaphore3");
    mutex1 = sem_open("/semaphore3", O_CREAT,  0644, 1);
    sem_unlink("/semaphore4");
    r = sem_open("/semaphore4", O_CREAT,  0644, 1);
    sem_unlink("/semaphore5");
    wrt = sem_open("/semaphore5", O_CREAT,  0644, 1);


    rw = (ReaderWriter *)mmap(NULL , sizeof(ReaderWriter), PROT_READ | PROT_WRITE , MAP_SHARED | MAP_ANONYMOUS , -1, 0);
    rw->data = -1;
    rw->readcount = 0;
    rw->writecount = 0;

    pid = fork();

    if(pid < 0)
      perror("Error\n");
    else if(pid == 0){
        for(i = 0;i < wc;i++){
              if(!fork()){
              sleep(2);
              sem_wait(mutex2);
              rw->writecount = rw->writecount+1;
              if(rw->writecount==1)
                sem_wait(r);
              sem_post(mutex2);
              sem_wait(wrt);
              rw->data = i;
              //strcat(rw->data,"Hello");
              //printf("%s");
              //strcpy(rw->data,s);
              printf("Data writen by the writer %d is %d\n",i,rw->data);
              sem_post(wrt);
              sem_wait(mutex2);
              rw->writecount = rw->writecount-1;
              if(rw->writecount==0)
                sem_post(r);
              sem_post(mutex2);
              exit(1);
        }
      }
      for(i = 0;i < wc;i++)
        wait(NULL);
      exit(1);
    }
    else
    {
        for(i = 0;i < rc;i++){
        if(!fork()){
          sleep(2);
          sem_wait(mutex3);
          sem_wait(r);
          sem_wait(mutex1);
          rw->readcount = rw->readcount + 1;
          if(rw->readcount==1)
           sem_wait(wrt);
          sem_post(mutex1);
          sem_post(r);
          sem_post(mutex3);
          printf("Data read by the reader %d is %d\n",i,rw->data);
          sem_wait(mutex1);
          rw->readcount = rw->readcount - 1;
          if(rw->readcount==0)
          sem_post(wrt);
          sem_post(mutex1);
          exit(1);
    }
    }
    for(i = 0;i < rc;i++)
        wait(NULL);
    }
    wait(NULL);
    sem_close(mutex3);
    sem_unlink("/semaphore1");
    sem_close(mutex2);
    sem_unlink("/semaphore2");
    sem_close(mutex1);
    sem_unlink("/semaphore3");
    sem_close(r);
    sem_unlink("/semaphore4");
    sem_close(wrt);
    sem_unlink("/semaphore5");
    return 0;
}
