//execl
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	int option,stat;
	while(1)
	{
		printf("1:Exec\n0:Exit");
		scanf("%d",&option);
		if(!option)
		{
			exit(0);
		}
		if(fork()==0)
		{
			execl("/home/khushi/10_3_22-5","./a.out",NULL);
			exit(0);
		}
		
	}
	return 0;
}
