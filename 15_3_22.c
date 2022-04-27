//Pthread once initialization
#include<stdio.h>
#include<pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *myinit()
{
	printf("Inside init\n");
}
void *mythread(void *i)
{
	printf("I am in mythread : %d\n",(int *)i);
	pthread_once(&once,(void *)myinit);
	printf("Exit from mythread : %d\n",(int *)i);
}

int main()
{
	pthread_t thread,thread1,thread2;
	pthread_create(&thread,NULL,mythread,(void *)1);
	pthread_create(&thread1,NULL,mythread,(void *)2);
	pthread_create(&thread2,NULL,mythread,(void *)3);
	printf("Exit for the main thread\n");
	pthread_exit(NULL);
	
}
	
