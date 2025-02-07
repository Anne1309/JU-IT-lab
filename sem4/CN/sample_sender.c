#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the data frame
typedef struct 
{
    int seq;
    char data[100];
} Frame;

// Function prototypes
void waitforevent();
void getdata(char* buffer);
void makeframe(Frame* frame, int seq, char* data);
void sendframe(Frame* frame);

int main() 
{
    Frame frame;
    char buffer[100];
    int seq = 0;

    while (1) 
    {
        waitforevent();
        getdata(buffer);
        makeframe(&frame, seq, buffer);
        sendframe(&frame);
        seq = !seq;
    }

    return 0;
}

void waitforevent() 
{
    // Implement waiting for an event (e.g., receiving data or acknowledgement)
}

void getdata(char* buffer) 
{
    // Implement reading data from the upper layer
    strcpy(buffer, "Example data");
}

void makeframe(Frame* frame, int seq, char* data) 
{
    frame->seq = seq;
    strcpy(frame->data, data);
}

void sendframe(Frame* frame) 
{
    // Implement sending the frame to the receiver
    printf("Sending frame (seq: %d, data: %s)\n", frame->seq, frame->data);
}

