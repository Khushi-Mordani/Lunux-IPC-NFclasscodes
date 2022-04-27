#include<stdio.h>
#include<pthread.h>

void * process(void *arg)
{
	pthread_detach(pthread_self());
	printf("Sleeping 2 secs\n");
	sleep(2);
	printf("Slept 2 secs\n");
}

int main()
{
	pthread_t tid;
	int errno=pthread_create(&tid,NULL,process,NULL);
	pthread_exit(NULL);
	return 0;
}
