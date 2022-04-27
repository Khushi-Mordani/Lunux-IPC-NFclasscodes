//Khushi Mordani
//Sending two messages at a time
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

//#define KEY 8979

typedef struct msgbuff
{
	long mtype;
	char buffer[100];
}msg;

int main()
{
	int qid,i;
	msg m1,m2;
	qid = msgget(32,IPC_CREAT|0644);
	m1.mtype = 10;
	for(i=0;i<100;i++)
	{
		m1.buffer[i] = 'a';
		m2.mtype = 20;
	}
	for(i=0;i<100;i++)
	{
		m2.buffer[i] = 'b';
	}
	i = msgsnd(qid,&m1,sizeof(msg),0);
	printf("Return value of As = %d\n",i);
	i = msgsnd(qid,&m2,sizeof(msg),0);
	printf("Return value of As = %d\n",i);
	return 0;
}

