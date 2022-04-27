#include<unistd.h>
#include<stdio.h>

int main()
{
	size_t i;
	const int alloc_size = 32*1024*1024;
	char* memory = malloc(alloc_size);
	mlock(memory,alloc_size);
	for(i=0;i<alloc_size;i++)
	{
		memory[i]='#';
	}
	printf("Allocated memory initialized with=%s\n",memory);
	munlock(memory,alloc_size);
	return 0;
}
