//Khushi Mordani
#include<stdio.h>
#include<signal.h>

void sighand(signal)
{
	printf("INterrupt signal recorded but no termination on CTRL + C\n");
	if(signal == SIGINT)
		printf("Received a sigint signal\n");

	exit(0);
}

int main()
{
	int i;
	signal(SIGINT,sighand);
	for(i=0;;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
}
