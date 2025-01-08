#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<sys/stat.h>
#include<semaphore.h>
int main()
{  
   sem_t *s1,*s2,*s3,*s4;
   s1=sem_open("/n1",O_CREAT,0620,1);
   s2=sem_open("/n2",O_CREAT,0620,0);
   s3=sem_open("/n3",O_CREAT,0620,0);
   s4=sem_open("/n4",O_CREAT,0620,0);
   if(fork()==0){
         sem_wait(s4);
         fprintf(stderr," boring ");
         
    }
   else if(fork()==0){
         sem_wait(s1);
         fprintf(stderr," PPWC ");
         sem_post(s2);
    }
   else if(fork()==0){
        sem_wait(s2);
        fprintf(stderr," is ");
        sem_post(s3);
    }
   else if(fork()==0){
         sem_wait(s3);
         fprintf(stderr," very ");
         sem_post(s4);
    }
   else{
        while(wait(NULL)>0);
        fprintf(stderr,"\n");
        sem_close(s1);
        sem_close(s2);
        sem_close(s3);
        sem_close(s4);
        sem_unlink("/n1");
        sem_unlink("/n2");
        sem_unlink("/n3");
        sem_unlink("/n4");
   }
   return 0;
}
   






  
   

  
  
