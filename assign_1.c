//. The child process send two numbers to the parent process via message queue.
// The parent process calculate the sum and return via same message queue.
//The child process print the result and exit. The parent process wait for completion of the child and then exit.



#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/msg.h>

#define MY_KEY   0x00001111
typedef struct msg{
    long type;
    int num1,num2;
}msg_t;

typedef struct res{
    long type;
    int result;
}res_t;

int main()
{
    int i,ret,s,mqid;
    msg_t m2;
    res_t m1;
     mqid=msgget(MY_KEY,IPC_CREAT|0600);
     if(mqid<0){
        printf("msgger() faild\n");
        _exit(1);
     }

    ret=fork();
    if(ret==0){
        //child
        
          printf("Enter two numbers :");
            scanf("%d%d",&m2.num1,&m2.num2);
                 m2.type=100;
                // m2.type=m2.num2;
        msgsnd(mqid,&m2,sizeof(m2.type),0);

        msgrcv(mqid,&m1,sizeof(m1.type),10,0);
       printf("add succes");
   
    }
   else{
    //parent
    
    printf("parent: wait for input\n");
  

    msgrcv(mqid,&m2,sizeof(m1.type),100,0);
       m1.result=m2.num1+m2.num2;
       printf("Sum : %d\n",m1.result);

   m1.type=10;
    msgsnd(mqid,&m1,sizeof(m1.result),0);

    waitpid(-1,&s,0);
    msgctl(mqid, IPC_RMID, NULL);
   }




    return 0;
}