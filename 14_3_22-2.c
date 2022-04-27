//Khushi Mordani
/*1.Write a multithreading program, where threads runs same shared global variable of the process between them.*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sharedvar=49;

void *thread_mul(void *arg)
{
	int n;
	printf("Enter a number to multiply:");
	scanf("%d",&n);
	sharedvar = sharedvar * n ;
	printf("After multiplication,shared variable is %d\n",sharedvar);
}

void *thread_sub(void *arg)
{
	int i;
	printf("Enter a number to subtract:");
	scanf("%d",&i);
	sharedvar = sharedvar - i;
	printf("\nAfter subtracting,shared variable is %d\n",sharedvar);
}

int main()
{
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,thread_mul,NULL);
	pthread_create(&thread2,NULL,thread_sub,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("Shared variable final value= %d\n",sharedvar);
	return 0;
}
