//Memory management
//memset

#include<stdio.h>
#include<string.h>

int main()
{
	const char str[] = "Hello!!,How are you??";
	const char ch ='#';
	printf("String before set is %s\n",str);
	memset(str,ch,strlen(str));
	printf("String after set is %s\n",str);
	

	//memrchr : reverse scanning
	/*char *ret1;
	const char c1 = '$';
	ret1 = memrchr(str,ch,strlen(str));
	printf("String after %c is - %s\n",c1,ret1);
	*/
	return 0;
}
