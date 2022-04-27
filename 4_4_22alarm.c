//Khushi Mordani

#include<stdio.h>
#include<signal.h>

void sighand(int signum)
{
	printf("Wake up wake up!!!\n");
}

int main()
{
	signal(SIGALRM,sighand);
	alarm(1);
	while(1)
	{
	}
	return 0;
}
