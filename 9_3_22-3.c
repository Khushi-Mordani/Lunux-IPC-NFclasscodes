#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid_1,pid_2;
	printf("Current process = %d\n",getpid());
	pid_1=fork();
	pid_2=vfork();
	if(pid_1==0)
	{
		//sleep(5);
		printf("New child process : %d\n",getpid());
		printf("New child parent : %d\n",getppid());
	}
	else
	{
		//sleep(3);
		printf("Parent pid:%d\n",getpid());
		printf("Parent's parent pid:%d\n",getppid());	
	}
	//while(1);
	printf("PID_2:%d\n",pid_2);
	return 0;
}
