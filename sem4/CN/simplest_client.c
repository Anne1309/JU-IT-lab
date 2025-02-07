#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>

char* ReceiveFrame() 
{
	short int n=0;
        int len=100;
        unsigned int addrlen;
        unsigned short serv_port=25000;
        short sockfd;
        char serv_ip[]="127.0.0.1";
        char mesg[1000];
	char* client;
        struct sockaddr_in servaddr, clientaddr;
	addrlen = sizeof(servaddr);
        client = (char*) malloc(addrlen);
        sockfd=socket(AF_INET, SOCK_DGRAM,0);
        if(sockfd<0)
        {
            printf("failed");
            exit(1);
        }
        bzero(&servaddr, addrlen);
        servaddr.sin_family=AF_INET;
        inet_aton(serv_ip, &servaddr.sin_addr);
        servaddr.sin_port=htons(serv_port);
        bind(sockfd,(struct sockaddr *)&servaddr, addrlen);
        n=recvfrom(sockfd,mesg,len,0,(struct sockaddr*)&clientaddr, &addrlen);
	if(n == -1)
	{
		printf("\n\tReceive failure.\t\n");
		exit(EXIT_FAILURE);
	}
	
	char* DataCopy = (char*)malloc((strlen(mesg)+1)*sizeof(char));
	strcpy(DataCopy,mesg);

    	return DataCopy; 
}

// Extract the data from the received frame
char* ExtractData(char* frame) 
{
    	// Implementation specific to extracting the data from the frame
    	return frame; // In this case, the frame is the same as the data
}

// Deliver the extracted data to the higher layers
void DeliverData(char* data) 
{
    	// Implementation specific to delivering the data
    	printf("Received data: %s\n", data);
}


int main()
{
	char* receivedFrame = ReceiveFrame();
    	char* extractedData = ExtractData(receivedFrame);
    	DeliverData(extractedData);
	return 0;
}
