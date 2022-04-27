#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
	int fd;
	char buff(300); //buffer empty
	int res;
	fd = open("maxfds.c",O_CREATE | O_RDWR,0777);
	if(fd<0)
	{
		fd = buff;
	}
	else
	{
		printf("Fd returned :%d\n",fd);
	}

}
