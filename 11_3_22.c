//threads
//enter -lpthread while compiling with gcc
#include<stdio.h>
#include<pthread.h>


static void* thread1(void *arg)
{
	char *s=(char *)arg;
	printf("%s\n",s);
	return 0;
}


int main(int argc,char *argv[])
{
	pthread_t t1;
	void *res;
	int s;
	s = pthread_create(&t1,NULL,thread1,"Hello!");
	printf("Messages from main ");
	sleep(3);
	exit(0);
}
