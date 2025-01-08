#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[]){
    int i,n;
    pid_t childpid;
    if(argc!=2){
        fprintf(stderr,"%s",argv[0]);
        return 1;
    }
    n=atoi(argv[1]);
    for(i=1;i<n;i++){
        if((childpid=fork())<=0)
        break;
    }
    fprintf(stderr,"%d %ld %ld %ld\n",i,(long)getpid(),(long)getppid(),(long)childpid);\
    return 0;
}