//Program having fork,exec,wait

#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int pid_1,pid_2;
	printf("Current process = %d\n",getpid());
	pid_1=fork();
	if(pid_1==0)
	{
		//sleep(5);
		printf("New child process : %d\n",getpid());
		printf("New child parent : %d\n",getppid());
		int ret = execl(argv[1],argv[2],0);
	}
	else
	{
		//sleep(3);
		wait(0);
		printf("Parent pid:%d\n",getpid());
		printf("Parent's parent pid:%d\n",getppid());	
	}
	//while(1);
	return 0;
}
