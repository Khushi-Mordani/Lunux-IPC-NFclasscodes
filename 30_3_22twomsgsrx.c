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

typedef struct msgbuff
{
	long mtype;
	char data[100];
}msg;

int main()
{
	int qid,i;
	msg m1,m2;
	qid =  msgget(32,IPC_CREAT|0644);
	i = msgrcv(qid,&m1,sizeof(msg),10,0);
	for(i=0;i<50;i++)
	{
		printf("%c",m1.data[i]);
	}
	printf("\n");
	i = msgrcv(qid,&m2,sizeof(msg),20,0);
	for(i=0;i<50;i++)
		printf("%c",m2.data[i]);
	printf("\n");
	return 0;
}

