#include<stdio.h>
#include<string.h>

int memcopy(char *src,char *des,int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		*des = *src;
		des++;
		src++;
	}
}

int main()
{
	const char src[10] = "Hey there!";
	const char des[10] ;
	memcopy(src,des,10);
	printf("String in destination=%s\n",des);
	return 0;
}
