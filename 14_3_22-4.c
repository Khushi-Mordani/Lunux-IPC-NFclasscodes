//Spinlock locking and unlocking

#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>
#include<stdio.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockthread(void *i)
{
int rc;
int count=0;
printf("entert thread %d,getting spin lock \n",(int *)i);
rc=pthread_spin_lock(&slock);
printf("%d thread unlock the spin lock\n",(int *)i);
rc=pthread_spin_unlock(&slock);
return NULL;
}

int main()
{
int rc=0;
pthread_t thread,thread1;
if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0)
perror("init");
printf("main get spin lock\n");
rc=pthread_create(&thread,NULL,spinlockthread,(int *)1);
printf("main wait a bit holding the spin lock\n");
sleep(5);

printf("main,now unlock the spinlock\n");
rc=pthread_spin_unlock(&slock);

if(rc==0)

printf("\n main thread sucessfully unlocked\n");

else

printf("\n main thread unsucessfully unlocked\n");

printf("main,wait for the thread to end\n\n");
rc=pthread_join(thread,NULL);
printf("main complete\n");
pthread_exit(NULL);
return 0;
}
