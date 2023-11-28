#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
 int ret,cnt=0,status;
 while(1)
 {
    ret=fork();
    if(ret<0)
    {
        perror("fork() failed");
        break;
    }
    if(ret==0)
    {
     sleep(10);
     _exit(0);
    }
    else
    cnt++;
 }
 printf("number of processcreat: %d\n",cnt);
 while(waitpid(-1,&status,0)>0)
  ;

    return 0;
}