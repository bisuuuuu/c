#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<unistd.h>
int main(){
    pid_t childpid;
    childpid=fork();
    if(childpid==-1){
        printf("error");
        return 1;
    }
    else if(childpid==0){
        printf("child id %ld ppid %ld\n",(long)getpid(),(long)getppid());
        sleep(100);
        printf("child id %ld ppid %ld\n",(long)getpid(),(long)getppid());
    }
    else{
         printf("parent id %ld ppid %ld\n",(long)getpid(),(long)getppid());
        exit(0);
    }
    return 0;
}