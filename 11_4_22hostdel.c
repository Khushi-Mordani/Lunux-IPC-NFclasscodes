//Khushi Mordani

#include<netdb.h>
#include<stdio.h>
#include<netinet/in.h>

int main()
{
	struct hostnet *he = NULL;
	char dotaddr[20];
	he = gethostbyname("196.12.100.100");

	inet_ntop(AF_INET, he->h_addr,dotaddr,20);
	printf("Address in dd notation = %s\n",dotaddr);
	return 0;
}

//nahi chal raha apna
