//memcpy

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *str1 = "Linux";
	char *str2 = " Kernel";
	char *name = (char *)alloca(strlen (str1) + strlen(str2) + 1);
	stpcpy(stpcpy (name,str1),str2);
	printf("The copied string data is %s\n",name);
	return 0;
}
