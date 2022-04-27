#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("My Process pid :%d\n",getpid());
	printf("Parent pid :%d\n",getppid());
	while(1)
	return 0;
}
