//Khushi Mordani

#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char buf[200];
	char *serv_ip = "127.0.0.1";
	int n;
	int sock_fd, ret_val;
	struct sockaddr_in servaddr;
	sock_fd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8000);
	inet_pton(AF_INET, serv_ip, &servaddr.sin_addr);
	
	ret_val = connect(sock_fd,(struct sockaddr *)&servaddr, sizeof(servaddr));
	if(ret_val < 0)
	{
		perror("Connect:");
		exit(1);
	}
	printf("Enter the data that you want to send to the server\n");
	gets(buf);
	Write(sock_fd,buf,strlen(buf));
	n = read(sock_fd,buf,200);
	buf[n] = '\0';
	printf("Recorded &s from server\n");
	close(sock_fd);
}
