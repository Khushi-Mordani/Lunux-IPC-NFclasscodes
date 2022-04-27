//mmap munmap
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main()
{
	char *c;
	c = mmap(0,50,PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1,0);
	perror("mmap");
	strcpy(c,"Linux kernel");
	printf("%s\n",c);
	munmap(c,50);
	return 0;
}
