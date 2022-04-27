//memchar : scanning
#include<stdio.h>
#include<string.h>

int main()
{
	const char str[] = "Hello!!,How are you??";
	char *ret;
	const char c = ',';
	ret = memchr(str,c,strlen(str));
	printf("String after %c is - %s\n",c,ret);
	return 0;
}

