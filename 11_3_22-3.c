#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>

void* th(void* p);

int fd;
int main()
{
pthread_t t1,t2;
fd=open("/etc/passwd",O_RDONLY);
printf("file open with fd:%d\n",fd);
pthread_create(&t1,NULL,th,"thread one");
pthread_create(&t2,NULL,th,"thread two");

pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
void* th(void* p)
{
char* str,buff[100];
int n,pid;
str=(char*)p;
pid=getpid();
printf("%s:\t start now: \tfor process %d\n\n",str,pid);
do
{
n=read(fd,buff,100);
printf("%s:\t read: \t %d \n\n",str,pid);
printf("\n-------------------\n");
write(1,buff,n);
printf("\n-------------------\n");
sleep(3);
}
while(n);
printf("%s:\t finished:\t for process %d\n\n",str,pid);
}
