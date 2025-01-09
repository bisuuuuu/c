#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
  sem_t *S,*T; //two semaphores
  //open the semaphore and initalize
 pid_t pid;
 char *n1="/name1";
 char *n2="/nam2";
 S=sem_open(n1, O_CREAT| O_RDWR,0644,0);
 T=sem_open(n2,O_CREAT| O_RDWR,0644,1);
  pid=fork();
  if(pid==0){// process P
   while(1){
         //entry section
       sem_wait(S);
       sleep(1);
       fprintf(stderr,"1");
       fprintf(stderr,"1");
      //remainder section
       sem_post(T);
   }
  }

  else{ //process Q
      while(1){
        //entry section
        sem_wait(T);
        sleep(1);
        fprintf(stderr,"0");
        fprintf(stderr,"0");
       //remainder section
        sem_post(S);
    }
    sem_close(S);
    sem_close(T);
    sem_unlink(n1);
   sem_unlink(n2);
}
 return 0;
}
