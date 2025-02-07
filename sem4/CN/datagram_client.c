/*
 * NAME: Siddharth Banerjee
 * ROLL: 002111001097
 * CLASS: BE IT UG2 A1
 */

/*
 * ASSIGNMENT 1, PROBLEM 2, part i
 * This program is to create a UDP datagram client socket to send a message to the server.
 */

/*
 * COMPILATION: gcc -Wall -g -o dc datagram_client.c
 * EXECUTION: ./dc
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

int main()
{
	
	//-----VARIABLE DECLARATIONS-----
	int sockfd,returnvalue,len = 100,n;
	unsigned int addrlen;
	unsigned short serv_port = 25000; //using an unused port
	char serv_ip[] = "172.16.5.3"; // loopback IP address
	char rtext[] = "\n\t\t\tHello\n";
	struct sockaddr_in servaddr;

	//assinging values, bind()
	addrlen = sizeof(servaddr);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(serv_port);
	inet_aton(serv_ip,&servaddr.sin_addr);
	sockfd = socket(PF_INET,SOCK_DGRAM,0);//opening socket
	
	//sending message to server
	returnvalue = sendto(sockfd,rtext,strlen(rtext),0,(struct sockaddr* ) &servaddr, sizeof(servaddr));
	//checking if the message was sent successfully or not
	if(returnvalue != -1)
	{
		printf("\n\t\t\tsent successfully\n");
	}
	else
	{
		printf("\n\t\t\tfailed to send\n");
	}
	//receiving message bak from server
	n = recvfrom(sockfd,rtext,len,0,(struct sockaddr*)&servaddr,&addrlen);
	if(n!= -1)
	{
		rtext[n] = '\0';
		printf("%s\n",rtext);
	}
	//closing socket
	close(sockfd);
}

