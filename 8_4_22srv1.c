// Khushi Mordani

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int listfd, connfd, retval;
	// pid_t childpid;
	socklen_t clien;
	struct sockaddr_in cliaddr, servaddr;

	listfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listfd < 0)
	{
		perror("sock:");
		exit(1);
	}
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(8000);

	retval = bind(listfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if (retval < 0)
	{
		perror("bind :");
		exit(2);
	}
	listen(listfd, 5);
	while (1)
	{
		clien = sizeof(cliaddr);
		connfd = accept(listfd, (struct sockaddr *)&cliaddr, &clien);
		printf("client connected\n");
	}
}
