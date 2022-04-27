//threads
//enter -lpthread while compiling with gcc
#include<stdio.h>
#include<pthread.h>


static void* thread1(void *arg)
{
	char *s=(char *)arg;
	printf("%s\n",s);
	return (void*) strlen(s);
	return 0;
}


int main(int argc,char *argv[])
{
	pthread_t t1;
	void *res;
	int s;
	s = pthread_create(&t1,NULL,thread1,"Hello!");
	printf("Messages from main \n");
	sleep(3);
	pthread_join(t1,&res);
	printf("Thread returned %ld\n",(long )res);
	exit(0);
}
