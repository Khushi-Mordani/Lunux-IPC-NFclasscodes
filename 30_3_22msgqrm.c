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

int main()
{
	int qid;
	struct msqid_ds buf;
	qid=msgget(49,IPC_CREAT|0644);
	printf("qid = %d\n",qid);
	msgctl(qid,IPC_RMID,&buf);
	/*printf("here are the details of the queue\n");
	printf("no of msg's in q %hi\n",buf.msg_qnum);
	printf("max no of bytes in q %hi\n",buf.msg_qbytes);*/
}



