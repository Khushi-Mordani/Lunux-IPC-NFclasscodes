//Khushi Mordani
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,fd3,fd4,fd5,fd6;
	fd1 = open("errors.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	fd2 = open("Even.txt",O_WRONLY | O_CREAT | O_TRUNC, 0777);
	printf("fd1 returned : %d\n",fd1);
	printf("fd2 returned : %d\n",fd2);
	fd3 = dup(fd1);//generates duplicate of the given fd in argument
	printf("fd3 returned: %d\n",fd3);
	fd4=dup2(fd1,4); //generates user defined file descriptor
	printf("fd4 returned: %d\n",fd4);
	fd5 = fcntl(fd1,F_DUPFD); //Command : generate a duplicate 
	printf("fd5 returned: %d\n",fd5);
	fd6 = fcntl(fd1,F_DUPFD,50); //Command : generate a duplicate 
	printf("fd6 returned: %d\n",fd6);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	return 0;
}
