#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main()
{
	char *c;
	c = mmap(0,50,PROT_READ | PROT_WRITE ,MAP_ANONYMOUS | MAP_PRIVATE,-1,0);
	perror("MAP");
	...
}
