//Creating multiple threads 
//Passing structure object as an argument

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct my_thread
{
	int thread_id;
	char msg[100];
};

void *printhello(void *threadob)
{
	pthread_t thread_Id;
	struct my_thread *t1;
	t1 = (struct my_thread *)threadob;
	thread_Id = pthread_self();
	printf("Thread id:%u\n",thread_Id);
	printf("%d Thread message:%s\n",t1->thread_id,t1->msg);
}

int main()
{
	pthread_t thread2,thread3,thread4,thread_Id;
	int rc;
	struct my_thread t2,t3,t4;
	t4.thread_id = 4;
	strcpy(t4.msg,"Fourth Thread");
	t2.thread_id = 2;
	strcpy(t2.msg,"Second Thread");
	t3.thread_id = 3;
	strcpy(t3.msg,"Third Thread");
	thread_Id = pthread_self();
	printf("Main thread id : %u\n",thread_Id);
	pthread_create(&thread4,NULL,printhello,(void *)&t4);
	pthread_create(&thread2,NULL,printhello,(void *)&t2);
	pthread_create(&thread3,NULL,printhello,(void *)&t3);
	printf("Exit from main thread\n");
	pthread_exit(NULL);
	
}
