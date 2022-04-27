//sched inherit and sched explicit
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void* Proc(void* param)
{
	sleep(3);
	return 0;
}

int main(int argc,char *argv[])
{
	pthread_attr_t Attr;
	pthread_t id;
	int err,info;
	pthread_attr_init(&Attr);
	pthread_attr_getinheritsched(&Attr,&info);
	switch(info)
	{
		case PTHREAD_INHERIT_SCHED :
			printf("SCHED\n");
			break;
		case PTHREAD_EXPLICIT_SCHED :
			printf("Explicit\n");
			break;
	}
	pthread_attr_setinheritsched(&Attr,PTHREAD_EXPLICIT_SCHED);
	pthread_attr_getinheritsched(&Attr,&info);
	switch(info)
	{
		case PTHREAD_INHERIT_SCHED :
			printf("SCHED\n");
			break;
		case PTHREAD_EXPLICIT_SCHED :
			printf("Explicit\n");
			break;
	}
	printf("Process creating thread whose sched policy is given by thread task proc\n");
	pthread_create(&id,&Attr,Proc,NULL);
	pthread_join(id,NULL);
	return 0;
}
