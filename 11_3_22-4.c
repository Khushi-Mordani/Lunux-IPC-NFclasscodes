//Khushi Mordani
//2.Write a program where thread cancel itself.(use pthread_cancel())
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *print(void *threadid)
{
	printf("Hello,I am Khushi!!\n");
	while(1);
}

int main()
{
	pthread_t t1;
	int rc, t=0;
	printf("Creating thread\n");
	rc = pthread_create(&t1,NULL,print,NULL);
	printf("thread id: %u\n",t1);
	rc = pthread_cancel(t1);
	if(t==0)
	{
		printf("Thread cancelled!\n");
		printf("thread id: %u\n",t1);
	}
	return 0;
}
