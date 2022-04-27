//Mutex

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int sharedvar=5;

pthread_mutex_t my_mutex; //create mutex
void *thread_inc(void *arg)
{
	pthread_mutex_lock(&my_mutex); //take mutex
	sharedvar++;
	printf("After increment=%d\n",sharedvar);
	pthread_mutex_unlock(&my_mutex);	//release mutex
}

void *thread_dec(void *arg)
{
	pthread_mutex_lock(&my_mutex);	//take mutex
	sharedvar--;
	printf("After decrement=%d\n",sharedvar);
	pthread_mutex_unlock(&my_mutex);	//release semaphore
}

int main()
{
	pthread_t thread1,thread2;
	pthread_mutex_init(&my_mutex,NULL);
	pthread_create(&thread1,NULL,thread_inc,NULL);
	pthread_create(&thread2,NULL,thread_dec,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("Shared variable = %d\n",sharedvar);
	return 0;
}
