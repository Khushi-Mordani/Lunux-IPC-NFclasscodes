#include<stdio.h>
#include<string.h>

void myprint(char *msg)
{
	if(msg!=NULL)
		printf("Message:%s\n",msg);
}

int main()
{
	char buff[]="Linux";
	myprint(NULL);
	return 0;
}
