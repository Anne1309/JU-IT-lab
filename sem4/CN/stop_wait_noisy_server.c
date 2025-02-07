/*
 * NAME: Siddharth Banerjee
 * ROLL: 002111001097
 * CLASS: BE IT UG2 A1
 */

/*
 * ASSIGNMENT 2, PROBLEM 2
 * Implementing the Stop-n-wait protocol in C
 * This program is a UDP implementation of a server in a noisy channel following the Stop-n-wait protocol
 */

/*
 * COMPILATION INSTRUCTIONS: gcc -Wall -g -o swns stop_wait_noisy_server.c
 * INVOCATION: ./swns
 * To quit the program, type ^C in the termial where the client is executing, or wait for a transmission to fail.
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

typedef struct packet 
{
	char data[1000];
}Packet;

typedef struct frame 
{
    	int frame_type; // ACK:0, SEQ:1 FIN:2
   	int sq_no;
    	int ack;
    	Packet packet;
} Frame;

int NoisePercentage()
{
	return (rand()%10 == 0); // 10% failure rate
}

int main() 
{
    	int port = 8000; // Fixed port number 8000
    	int sockfd;
    	struct sockaddr_in servAddr, newAddr;
    	//char buffer[1024];
    	socklen_t addr_size;
	unsigned int addrlen = sizeof(servAddr);

    	int frame_id = 0;
    	Frame frame_recv;
    	Frame frame_send;

    	// Create a UDP socket
    	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    	// Set up the server address structure
	bzero(&servAddr,addrlen);
    	servAddr.sin_family = AF_INET;
    	servAddr.sin_port = htons(port);
    	servAddr.sin_addr.s_addr = INADDR_ANY;

    	// Bind the socket to the server address
    	bind(sockfd, (struct sockaddr*)&servAddr, addrlen);
    	addr_size = sizeof(newAddr);

	while(1)
	{
    	// Receive a frame from the client
        int f_recv_size = recvfrom(sockfd, &frame_recv, sizeof(Frame), 0, (struct sockaddr*)&newAddr, &addr_size);

        // Check if a frame was received and if it is a sequence frame with the expected sequence number
        if (f_recv_size > 0 && frame_recv.frame_type == 1 && frame_recv.sq_no == frame_id && !NoisePercentage()) 
	{
            	printf("[+]Frame Received: %s\n", frame_recv.packet.data);

            	// Prepare an acknowledgment frame
            	frame_send.sq_no = 0;
            	frame_send.frame_type = 0;
            	frame_send.ack = frame_recv.sq_no + 1;

            	// Send the acknowledgment frame back to the client
            	sendto(sockfd, &frame_send, sizeof(frame_send), 0, (struct sockaddr*)&newAddr, addr_size);
            	printf("[+]Ack Sent\n");
        } 
	else 
	{
            printf("[X]Frame Not Received\n");
        }

        // Increment the frame id to expect the next frame in sequence
        frame_id++;
	}
    	// Close the socket
    	close(sockfd);
    	return 0;
}

