#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,fd3,fd4;
	fd1 = creat("1.txt",777);
	fd2 = creat("2.txt",777);
	fd3 = creat("3.txt",777);
	printf("Fd1 returned :%d\n",fd1);
	printf("Fd2 returned :%d\n",fd2);
	printf("Fd3 returned :%d\n",fd3);
	int close(int fd1);
	int close(int fd2);
	int close(int fd3);
	fd4 = open("/home/1.txt",O_WRONLY);
	printf("Fd4 returned :%d\n",fd4);
	//read(int fd,void *buf,ssize_t nbytes)
	return 0;

}
