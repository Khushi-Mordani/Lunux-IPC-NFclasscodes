//Khushi Mordani

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<string.h>
#define KEY 8979

struct msgbuf
{
	long mtype;
	char data[512];
};


int main(int argc, char *argv[])
{
	struct msgbuf v;
	struct msqid_ds buf;
	int id;
	id=msgget(55,IPC_CREAT|0644);
	printf("id=%d\n", id);
	v.mtype=atoi(argv[1]);
	strcpy(v.data, argv[2]);
	msgsnd(id, &v, strlen(v.data)+1,0);
	msgctl(id,IPC_STAT,&buf);
	printf("here are the details of the queue\n");
	printf("no of msg's in q %hi\n",buf.msg_qnum);
	printf("max no of bytes in q %hi\n",buf.msg_qbytes);
	return 0;
}


