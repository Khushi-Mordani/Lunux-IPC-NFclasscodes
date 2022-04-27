#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mman.h>

void* proc(void* param)
{
	sleep(2);
	return 0;
}

int main()
{
	pthread_attr_t Attr;
	pthread_t id;
	void *stk;
	size_t siz;
	int err;
	size_t my_stksize = 0x30000000;
	void * my_stack;
	
	pthread_attr_init(&Attr);

	pthread_attr_getstacksize(&Attr, &siz);
	pthread_attr_getstackaddr(&Attr, &stk);
	
	printf("Default address: %08x Default size: %d\n",stk,siz);
	
	my_stack = (void*)malloc(my_stksize);
	
	pthread_attr_setstack(&Attr,my_stack,my_stksize);
	pthread_create(&id,&Attr,proc,NULL);
	pthread_attr_getstack(&Attr,&stk,&siz);
	printf("Newly derived stack address:%08x and size:%d\n,stk,siz");
	sleep(2);
	exit(0);

}
