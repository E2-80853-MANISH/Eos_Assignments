#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
// parent A -> child B -> child C
int main()
 {
    int i, pid1,pid2,pid3,pid4,pid5,s1,s2,s3,s4,s5;
    pid1=fork();
    if(pid1==0)
    {
    for(i=1; i<=5; i++) 
    {
        printf("A. %d\n", i);
        sleep(1);
    }
       _exit(0);
    }
    pid2=fork();
    if(pid2==0)
    {
    for(i=1; i<=5; i++) 
    {
        printf("B. %d\n", i);
        sleep(1);
    }
       _exit(0);
    }
    pid3=fork();
    if(pid3==0)
    {
    for(i=1; i<=5; i++) 
    {
        printf("C. %d\n", i);
        sleep(1);
    }
       _exit(0);
    }
    pid4=fork();
    if(pid4==0)
    {
    for(i=1; i<=5; i++) 
    {
        printf("D. %d\n", i);
        sleep(1);
    }
       _exit(0);
    }
    pid5=fork();
    if(pid5==0)
    {
    for(i=1; i<=5; i++) 
    {
        printf("e. %d\n", i);
        sleep(1);
    }
       _exit(0);
    }



    {
        for(i=1; i<=5; i++)
     {
        printf("parent. %d\n", i);
        sleep(1);
    }
    
waitpid(pid1,&s1,0);
waitpid(pid2,&s2,0);
waitpid(pid3,&s3,0);
waitpid(pid4,&s4,0);
waitpid(pid5,&s5,0);
    }

        
    return 0;

    }