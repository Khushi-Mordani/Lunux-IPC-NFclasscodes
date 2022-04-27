#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

struct my_thread
{
	int thread_id;
	char msg[100];
};

void *Printhello(void *threadobj)
{
	pthread_t thread_ID;
	struct my_thread *t1;
	t1 = (struct my_thread *)threadobj;
	thread_ID = pthread_self();
	printf("Thread id:%u\n",thread_ID);
	printf("%d Thread message : %s\n",t1->thread_id,t1->msg);
}


int main()
{
	pthread_t thread4,thread_ID;
	int rc;
	struct my_thread t4;
	t4.thread_id = 4;
	strcpy(t4.msg,"Inside fourth thread\n");
	t4.thread_id = pthread_self();
	printf("Main thread id: %u\n",t4.thread_id);
	pthread_create(&thread4,NULL,Printhello,(void *)&t4);
	printf("Exit from main thread\n");
	pthread_exit(NULL);
	return 0;
}
//not getting desired output
