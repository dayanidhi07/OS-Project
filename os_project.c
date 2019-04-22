/*

A) The first known correct software solution to the critical-section problem
for two processes was developed by Dekker. The two processes, P0 and P1 , share the following
variables:
boolean flag[2]; (initially false)
int turn;
The structure of process Pi is ( I == 0 or 1) ; the other process is Pj (j== 1 or 0). Write a program which satisfies all three requirements for the critical-section problem.

B) Write a program for the Swap () instruction can be used to provide mutual exclusion that satisfies the
bounded-waiting requirement.

CODE
*/

#include<pthread.h>
#include<stdio.h>
void *P0(void *);
void *P1(void *);
int flag[2];
int turn=0;
int global=100;
int main()
{
    pthread_t pid1,pid2;
    pthread_create(&pid1,NULL,P0,NULL);
    pthread_create(&pid2,NULL,P1,NULL);
    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);
}

void *P0(void *val)
{
    int i=0;
    while(i<2)
    {
        flag[0]=1;
        turn=1;
        while(flag[1]==1 && turn==1)
	printf("Critical Section");

        global+=100;
        printf("\n Remainder Section %d",global);
        flag[0]=0;
        i++;
    }
}
void *P1(void *val)
{
    int i=0;
    while(i<2)
    {
        flag[1]=1;
        turn=0;
        while(flag[0]==1 && turn==0)
	printf("Critical Section");

        global-=75;
        printf("\n Remainder Section %d",global);
        flag[1]=0;
        i++;
    }
}
