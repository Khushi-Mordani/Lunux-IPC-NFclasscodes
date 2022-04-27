//Khushi Mordani

#include<sys/types.h>
#include<signal.h>
#include<stdio.h>

int main()
{
	pid_t pid;
	int sig_no;
	printf("Enter the pid:");
	scanf("%d",&pid);
	printf("Enter the signal:");
	scanf("%d",&sig_no);
	perror("Sig_res:");
}

