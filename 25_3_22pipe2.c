//Khushi Mordani

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int fds[2];

void parent_code()
{
	char *buff1 = "aaaaaaaaaaaaaaaaa";
	char *buff2 = "bbbbbbbbbbbbbbbbbbb";
	close(fds[0]);
	write(fds[1],buff1,20);
	write(fds[1],buff2,20);
	printf("End of parent!\n");
}

void child_code()
{
	char buff[100];
	int n, i;
	close(fds[1]);
	n = read(fds[0],buff,100);
	printf("Number of characters read = %d\n",n);
	for(i=0;i<n;i++)
		printf("%c",buff[i]);
	printf("End of child!\n");
}

int main()
{
	int res, i;
	pid_t p;
	res = pipe(fds);
	if(res == -1)
	{
		perror("pipe");
		exit(1);
	}
	p = fork();
	if(p==0)
	{
		child_code();
	}
	else
	{
		parent_code();
	}
	return 0;
}
