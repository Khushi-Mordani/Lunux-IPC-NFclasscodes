//Khushi Mordani

#include<stdio.h>
#include<unistd.h>

int main()
{
	int fds[2];
	int res,i;
	char *buff1 = "aaaaaaaaaaaaaaaaa";
	char *buff = "bbbbbbbbbbbbbbbbbbb";
	char buff2[40];
	
	res = pipe(fds);
	
	if(res == -1)
	{
		perror("pipe");
		exit(1);
	}
	write(fds[1],buff1,20);
	write(fds[1],buff,20);
	read(fds[0],buff2,40);
	for(i=0;i<40;i++)
		printf("%c",buff2[i]);
	printf("\n");
	return 0;
}
