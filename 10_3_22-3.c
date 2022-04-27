//wait_pid
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int pid;
	int status;
	printf("Parent:%d\n",getpid());
	pid = fork();
	if(pid == 0)
	{
		printf("Child:%d\n",getpid());
		sleep(2);
		exit(0);
	}
	printf("Parent reporting to the child whose pid =  %d\n",waitpid(pid,&status,0));
	return 0;
}

