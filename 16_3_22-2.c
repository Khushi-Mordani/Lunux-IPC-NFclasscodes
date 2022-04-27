//memcpy
//memcmp
#include<stdio.h>
#include<string.h>

int main()
{
	char buf1[10],buf2[10];
	int ret;
	memcpy(buf1,"madam",5);
	memcpy(buf2,"mad",5);
	ret = memcmp(buf1,buf2,5);
	
	if(ret > 0)
	{
		printf("buf1 is greater than buf2\n");
	}
	else if(ret < 0)
		printf("buf1 is less than buf2\n");
	else
		printf("buf1 is equal to buf2\n");
	return 0;

}
