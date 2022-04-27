//Khushi Mordani
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

struct msgbuf
{
	long mtype;
	char data[512];
};


int main(int argc, char *argv[])
{
	struct msgbuf v;
	int id;
	if(argc!=2)
	{
		printf("iusage: ./mq_rx type \n");
		printf("example: mq_rx 5\n");
		return 0;
	}
	id=msgget(55, IPC_CREAT|0644);
	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	msgrcv(id, &v, sizeof(v), atoi(argv[1]), 0);
	printf("data %s\n", v.data);
	return 0;
}
