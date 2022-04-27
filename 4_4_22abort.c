//Khushi Mordani

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void abort_handler(int);

int main()
{
	if(signal(SIGABRT,abort_handler)==SIG_ERR)
	{
		fprintf(stderr,"Could not get signal handler\n");
		exit(1);
	}
	abort();
	exit(0);
}

void abort_handler(int i)
{
	fprintf(stderr,"Caught SIGABRT, exiting signal application\n");
	exit(1);
}
