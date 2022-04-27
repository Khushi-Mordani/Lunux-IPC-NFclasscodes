//threads
//enter -lpthread while compiling with gcc
#include<pthread.h>

pthread_t tid1,tid2;

void* thread1(void *arg)
{
	printf("Thread 1 is executing!\n");
	return NULL;
}

void* thread2(void *arg)
{
	printf("Thread 2 is executing!\n");
	return NULL;
}

int main()
{
	int ret1 = pthread_create(&tid1,NULL,thread1,NULL);
	if(ret1)
		printf("Thread is not created!\n");
	else
		printf("Thread is created!\n");
	//sleep(2);
	pthread_join(tid1,NULL);
	int ret2 = pthread_create(&tid2,NULL,thread2,NULL);
	if(ret2)
		printf("Thread is not created!\n");
	else
		printf("Thread is created!\n");
	//sleep(2);
	pthread_join(tid2,NULL);
	return 0;
}
