//Khushi Mordani

#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int p[2];
	pipe(p);
	printf("Read end of pipe : %d Write end of pipe : %d\n",p[0],p[1]);
	if(fork())
	{
		char s[20];
		printf("Enter data in parent\n");
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);
	}
	else
	{
		char buf[20];
		printf("In child!\n");
		read(p[0],buf,sizeof(buf));
		printf("Child process displaying the data from parent : %s\n",buf);
	}
	return 0;
}
