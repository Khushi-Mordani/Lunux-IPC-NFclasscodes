//Khushi Mordani
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

struct msgbuff
{
	long mtype;
	char data[512];
};

int main(int argc,char *argv[])
{
	struct msgbuff v;
	int id;
	id = msgget(55,IPC_CREAT | 0644);
	printf("id = %d\n",id);
	v.mtype = atoi(argv[1]);
	strcpy(v.data,argv[2]);
	msgsnd(id,&v,strlen(v.data)+1,0);
	return 0;
}

