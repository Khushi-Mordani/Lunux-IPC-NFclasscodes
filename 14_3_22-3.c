//semaphore locking and unlocking
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int sharedvar=5;

sem_t my_sem;
void *thread_inc(void *arg)
{
	sem_wait(&my_sem);
	sharedvar++;
	printf("After increment=%d\n",sharedvar);
	sem_post(&my_sem);
}

void *thread_dec(void *arg)
{
	sem_wait(&my_sem);	//take semaphore
	sharedvar--;
	printf("After decrement=%d\n",sharedvar);
	sem_post(&my_sem);	//release semaphore
}

int main()
{
	pthread_t thread1,thread2;
	sem_init(&my_sem,0,1);	//Initialize semaphore
	pthread_create(&thread1,NULL,thread_inc,NULL);
	pthread_create(&thread2,NULL,thread_dec,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("Shared variable = %d\n",sharedvar);
	return 0;
}
