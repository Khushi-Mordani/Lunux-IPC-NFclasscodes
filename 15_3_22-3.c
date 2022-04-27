#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *my(void *i)
{
	printf("Inside %d thread\n",(int *)i);
}

int main()
{
	pthread_t tid;
	struct sched_param param;
	int priority,policy,ret;
	ret = pthread_getschedparam(pthread_self(),&policy,&param);//process itself is a thread here.
	if(ret!=0)
		perror("Get sched param\n");
printf("Main thread!\nPolicy:%d Priority:%d\n",policy,param.sched_priority);
	policy = SCHED_FIFO;
	param.sched_priority = 3;
	ret = pthread_setschedparam(pthread_self(),policy,&param);
	if(ret!=0)
		perror("Get sched param\n");
	ret = pthread_setschedparam(pthread_self(),policy,&param);
	if(ret!=0)
		perror("Get sched param\n");
printf("Main thread!\nPolicy:%d Priority:%d\n",policy,param.sched_priority);
	
	return 0;
}
