#include<stdio.h>
#include<unistd.h>

int main()
{
	int ret;
	printf("Execution of ls program\n");
	//execl("/bin/ls","ls","-lh",0);
	execl("/home/khushi/9_3_22-3.c","./a.out",0);
	/*ret = execl("/usr/bin/vim","vim","info1.txt",0);
	if(ret ==0)
	{
		printf("Execl returned an error!\n");
	}*/
	printf("Completed execution of ls program");
	return 0;
}
