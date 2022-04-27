#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd,len;
	char wr_buff[50]="Hello!";
	char read_buff[50];

	fd = open("linux_kernel.txt",O_CREAT | O_RDWR,777);

	len = write(fd,wr_buff,50);
	printf("Write operation returned:%d\n",len);
	lseek(fd,0,SEEK_SET); //taking the cursor back to beginning
	read(fd,read_buff,len);
	printf("Data from buffer:%s\n",read_buff); //throws garbage
	close(fd);
	return 0;
}
