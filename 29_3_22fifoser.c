//Khushi Mordani
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	printf("Server - listening");
	int code = mkfifo("cli_ser_fifo",0764);
	if(code == -1)
	{
		perror("Mffifo returned an error - file may already exist");
	}
	int fd = open("cli_ser_fifo",O_RDONLY);
	if(fd == -1)
	{
		perror("Cannot open FIFO for read");
		return 0;
	}
	printf("FIFO Open");
	char serverrcv[100];
	memset(serverrcv,0,100);
	int res;
	char len;
	while(1)
	{
		res = read(fd,&len,1);
		if(res == 0)
		{
			break;
		}
		read(fd,serverrcv,len);
		printf("Server received : %s\n",serverrcv);
	}
	printf("EDF reached");
	close(fd);
	printf("FIFO closed");
	return 0;
}
