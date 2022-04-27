//wait
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int status;
	pid_t pid1;
	pid1=fork();
	if(pid1==0)
	{
		sleep(5);
		printf("After delay of 5.Child pid = %d\n",getpid());
	}
	else
	{
		int pid2;
		printf("Parent pid = %d\n",getpid());
		pid2 = wait(0);
		printf("Child termination successful\n");
		printf("Parent pid = %d\n",getpid());
	}
	
	return 0;
}
