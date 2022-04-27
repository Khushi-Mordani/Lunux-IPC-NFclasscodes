//atexit
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

void callback()
{
	printf("Callback function!\n");
}
void callback2()
{
	printf("Callback2 function!\n");
}
void callback3()
{
	printf("Callback3 function!\n");
}

int main()
{
	printf("Registering callback function\n");
	atexit(callback);
	printf("Registering callback2 function\n");
	atexit(callback2);
	printf("Registering callback3 function\n");
	atexit(callback3);
	printf("Main exiting\n");
	_exit(0);
}
