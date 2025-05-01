#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUF 1024

int main(int argc, char* argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUF] = {0};
    char message[MAX_BUF];
    struct timespec ts;
    int PORT = atoi(argv[1]);

    // Create socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set server address (you need to know the IP address of the server)
    char *server_ip = argv[2]; 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(server_ip);  

    while (1) {
        // Take input from user
        printf("Enter message to send: ");
        fgets(message, MAX_BUF, stdin);  // Read input from user
        message[strcspn(message, "\n")] = 0;  

        // Send data to server
        sendto(sock, message, strlen(message), 0, (const struct sockaddr *) &serv_addr, sizeof(serv_addr));
        printf("Sent: %s\n", message);

        // Wait for acknowledgment
        recvfrom(sock, buffer, MAX_BUF, MSG_WAITALL, NULL, NULL);
        printf("Received ACK: %s\n", buffer);

        // Simulate Stop-and-Wait: Wait for 2 seconds before sending the next message
        ts.tv_sec = 2;
        ts.tv_nsec = 0;
        nanosleep(&ts, NULL);  // Simulate delay (adjustable)
    }

    close(sock);
    return 0;
}
