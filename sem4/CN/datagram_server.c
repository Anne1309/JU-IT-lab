/*
 * NAME: Siddharth Banerjee
 * ROLL: 002111001097
 * CLASS: BE IT UG2 A1
 */

/*
 * ASSIGNMENT 1, PROBLEM 2, part i
 * This program is to create a UDP datagram server socket to echo a message back from the client.
 */

/*
 * COMPILATION: gcc -Wall -g -o ds datagram_server.c
 * EXECUTION: ./ds
 *
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>

int main()
{
	short int n=0,m=0;
	int len=100;
	int addrlen;
	unsigned short serv_port=25000;
	short sockfd;
	char serv_ip[]="172.16.5.6";
	char mesg[1000];
	char *client;
	struct sockaddr_in servaddr, clientaddr;
	client = (char*) malloc(sizeof(servaddr));
	sockfd=socket(AF_INET, SOCK_DGRAM,0);
	if(sockfd<0)
	{
	    printf("failed");
	    exit(1);
	}
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	inet_aton(serv_ip, &servaddr.sin_addr);
	servaddr.sin_port=htons(serv_port);
	bind(sockfd,(struct sockaddr *)&servaddr, sizeof(servaddr));
	n=recvfrom(sockfd,mesg,len,0,(struct sockaddr*)&clientaddr, &addrlen);
	if(n!=-1)
	printf("\n\t\t\t*** receive success***\n");
	else
	printf("\n\t\t\t*** receive failure ***\n");
	m=sendto(sockfd,mesg,n,0,(struct sockaddr *)&clientaddr, sizeof(clientaddr));
	if(m!=-1)
	printf("\n\t\t\t*** send success ***\n");
	else
	printf("\n\t\t\t*** send failure ***\n");
	close(sockfd);
	return 0;
}

