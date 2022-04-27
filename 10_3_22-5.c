//argc,argv : Manipulating command line arguments
#include<stdio.h>

int main(int argc, char *argv[])
{
	int i;
	printf("File name:%s\n",argv[0]);
	printf("Total number of arguments:%d\n",argc);
	for(i=1;i<argc;i++)
	{
		printf("%s",argv[i]);
	}
	execl("argv[1]","argv[2]",0);
	return 0;
}
