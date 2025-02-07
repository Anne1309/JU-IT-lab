/*
 * NAME: Siddharth Banerjee
 * ROLL: 002111001097
 * CLASS: BE IT UG2 A1
 */

/*
 * ASSIGNMENT 1, PROBLEM 2, part ii
 * This program is to create a TCP stream server socket to echo a message back to the client.
 */

/*
 * COMPILATION: gcc -Wall -g -o ss stream_socket.c
 * EXECUTION: ./ss
 *
 */


#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
int main()
{
	// creating variables
	int sockfd,returnvalue,len = 100,n;
	unsigned int addrlen;
	unsigned short serv_port = 8000;
	char serv_ip[] = "127.0.0.1";
	char text[] = "Hello";
	char rtext[100];
	struct sockaddr_in servaddr;
	
	addrlen = sizeof(servaddr);
	bzero(&servaddr, sizeof(servaddr));//setting all bits of sockaddr to 0 to avoid using garbage values
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(serv_port); // setting network byte order
	inet_aton(serv_ip,&servaddr.sin_addr);
	sockfd = socket(PF_INET,SOCK_STREAM,0); // creating the socket

	connect(sockfd,(struct sockaddr*) &servaddr, addrlen);
	
	returnvalue = write(sockfd,text,strlen(text)); // sending the message to the server
	if(returnvalue != -1)
	{
		printf("\nSEND SUCCESS.\n");
	}
	else
		printf("\nSEND FAILURE\n");

	n = read(sockfd,rtext,len); // receiving the message from the server
	rtext[n] = '\0';
	printf("\n%s\n",rtext);
	close(sockfd);	
}
