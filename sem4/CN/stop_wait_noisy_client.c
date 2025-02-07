/*
 * NAME: Siddharth Banerjee
 * ROLL: 002111001097
 * CLASS: BE IT UG2 A1
 */

/*
 * ASSIGNMENT 2, PROBLEM 2, PART ii
 * Implementing the Stop-n-wait protocol in C
 * This program is a UDP implementation of a client in a noisy channel following the Stop-n-wait protocol
 */

/*
 * COMPILATION INSTRUCTIONS: gcc -Wall -g -o swnc stop_wait_noisy_client.c
 * INVOCATION: ./swnc
 * The console waits for a string input (within 1000 characters).
 * To quit the program, type ^C in the terminal where the client is executing, or wait for a transmission to fail.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct packet 
{
    	char data[1000];
} Packet;

typedef struct frame 
{
    int frame_type; // ACK:0, SEQ:1 FIN:2
    int sq_no;
    int ack;
    Packet packet;
} Frame;

int NoisePercentage() // function to emulate a noisy channel
{
        return (rand()%10 == 0); // 10% failure rate
}


int main() 
{
    int port = 8000; // Fixed port number 8000
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[1000];

    unsigned int addrlen = sizeof(serverAddr);	
    int frame_id = 0;
    Frame frame_send;
    Frame frame_recv;
    int ack_recv = 1;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&serverAddr, addrlen);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    while(1)
    {
    	if (ack_recv == 1) 
	{
            frame_send.sq_no = frame_id;
            frame_send.frame_type = 1;
            frame_send.ack = 0;

            printf("Enter Data: ");
            scanf("%s", buffer);
            strcpy(frame_send.packet.data, buffer);

            // Send the frame to the server
            sendto(sockfd, &frame_send, sizeof(Frame), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
            printf("[+]Frame Sent\n");
        }

        unsigned int addr_size = sizeof(serverAddr);
        int f_recv_size = recvfrom(sockfd, &frame_recv, sizeof(frame_recv), 0, (struct sockaddr*)&serverAddr, &addr_size);

        if (f_recv_size > 0 && frame_recv.sq_no == 0 && frame_recv.ack == frame_id + 1 && !NoisePercentage()) {
            printf("[+]Ack Received\n");
            ack_recv = 1;
        } else 
	{
            printf("[X]Ack Not Received\n");
            ack_recv = 0;
        }

        frame_id++;
    }
    	close(sockfd);
    	return 0;
}

