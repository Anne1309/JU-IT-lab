#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>

void WaitForEvent()
{
	
	//create file descriptor set
	fd_set readfds;
	FD_ZERO(&readfds);

	//add relevant fd's to the set
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	FD_SET(sockfd,&readfds);

	//setting the timeout value to 5 seconds
	struct timeval timeout;
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;

	//wait for an event on the file descriptors
	int ready = select(FD_SETSIZE,&readfds,NULL,NULL,&timeout);

	if(ready == -1)
	{
		perror("select");
		exit(EXIT_FAILURE);
	}

	else if(ready == 0)
	{
		printf("Timeout occured\n");
	}

	else
		printf("Event Occured\n");
}

char* GetData()
{
	//define the string data
	char* data = "Hello receiver,testing";

	//creating a copy to send back to main()
	size_t length = strlen(data);
	char* dataCopy = (char*)malloc((length+1)*sizeof(char));

	if(dataCopy == NULL)
	{
		perror("Failed to allocate memory for data");
		exit(EXIT_FAILURE);
	}

	strcpy(dataCopy,data);
	return dataCopy;
}

char* MakeFrame(char* data)
{
	//calculate the length of the data
	size_t length = strlen(data);

	char* frame = (char*)malloc((length+1)*sizeof(char));
	if(frame == NULL)
	{
		perror("failed to allocate memory for frame");
		exit(EXIT_FAILURE);
	}

	strcpy(frame,data);
	return frame;

}

void SendFrame(char* rtext)
{
	

	int sockfd,returnvalue;
	unsigned int addrlen;
	unsigned short serv_port = 25000; //using an unused port
	char serv_ip[] = "127.0.0.1"; // loopback IP address
	struct sockaddr_in servaddr;

	//assinging values, bind()
	addrlen = sizeof(servaddr);
	bzero(&servaddr,addrlen);
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
		
}


int main()
{
	WaitForEvent();
	char* data = GetData();
	char* frame = MakeFrame(data);
	SendFrame(frame);
	return 0;
}
