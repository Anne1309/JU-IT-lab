/*
>Team: 08 , Date:28/7/25
>Name: Debodit Ray, Roll: 13
>Name: Kaustav Mondal , Roll: 17
>Name: Anuska Nath , Roll: 03

>Assignment description:

IPC using Named Pipe (FIFO):

Using the fork system call, create a Child Process.. Transfer 1GB file
from the Parent Process to Child Process using a FIFO. Now, transfer
the same file from the Child Process to the Parent Process using
another FIFO. Now, compare the two files(use cmp or diff command)
to make sure that the same file has returned back. Also, print the time
required to do this double transfer. Attach this output to the source file
as a comment.
To create FIFO, you can either use a shell command or a system call.
To create a large file you can use the relevant command.
Use ‘ls –l’ command to show the FIFO and the large file. Attach this
output to the source file as a comment.
Make sure that the starting comment block has all the necessary
information attached.



>Steps to compile: 

Commands:
$ gcc A3_08_02B.c -o ipc_fifo
$ dd if=/dev/zero of=originFile.txt bs=1M count=1024

Output:
1024+0 records in
1024+0 records out
1073741824 bytes (1.1 GB, 1.0 GiB) copied, 0.322038 s, 3.3 GB/s

Commands:
$ mkfifo fifo1 fifo2
$ ls -l

Output:
total 1048608
-rw-r--r-- 1 adminpc adminpc        397 Jul 29  2025 A3_08_02A.c
-rw-r--r-- 1 adminpc adminpc       3936 Jul 29 14:54 A3_08_02B.c
prw-rw-r-- 1 adminpc adminpc          0 Jul 29 15:02 fifo1
prw-rw-r-- 1 adminpc adminpc          0 Jul 29 15:02 fifo2
-rwxrwxr-x 1 adminpc adminpc      17184 Jul 29 15:01 ipc_fifo
-rw-rw-r-- 1 adminpc adminpc 1073741824 Jul 29 15:02 originFile.txt



>Steps to execute:

Command: 
./ipc_fifo

Output:
mkfifo fifo1: File exists
mkfifo fifo2: File exists
>>> Total round-trip time: 1354 ms



>Comparing two files:

Commad: 
cmp -s originFile.txt receivedBack.txt && echo "Files match" || echo " Files differ"

Output:
Files match

*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

// Function to calculate current time in milliseconds
long getTimeElapsed() {
    struct timeval timeElapsed;
    gettimeofday(&timeElapsed, NULL);
    return timeElapsed.tv_sec * 1000 + timeElapsed.tv_usec / 1000;
}

int main() {
    long startTime = getTimeElapsed();

    char *fifo1 = "fifo1";
    char *fifo2 = "fifo2";

    if (mkfifo(fifo1, 0666) == -1) perror("mkfifo fifo1");
    if (mkfifo(fifo2, 0666) == -1) perror("mkfifo fifo2");

    int pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process: read from fifo1, write to destFile.txt, then send back via fifo2
        int rfd = open(fifo1, O_RDONLY);
        if (rfd < 0) {
            perror("open fifo1");
            exit(1);
        }

        int out = open("destFile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
        if (out < 0) {
            perror("open destFile.txt");
            exit(1);
        }

        char buf[4096];
        ssize_t bytes;
        while ((bytes = read(rfd, buf, sizeof(buf))) > 0) {
            if (write(out, buf, bytes) != bytes) {
                perror("write to destFile.txt");
                exit(1);
            }
        }
        close(rfd);
        close(out);

        // Now read destFile.txt and write to fifo2
        out = open("destFile.txt", O_RDONLY);
        if (out < 0) {
            perror("reopen destFile.txt");
            exit(1);
        }

        int wfd = open(fifo2, O_WRONLY);
        if (wfd < 0) {
            perror("open fifo2");
            exit(1);
        }

        while ((bytes = read(out, buf, sizeof(buf))) > 0) {
            if (write(wfd, buf, bytes) != bytes) {
                perror("write to fifo2");
                exit(1);
            }
        }
        close(out);
        close(wfd);
    } else {
        // Parent process: read originFile.txt and send via fifo1
        int fd = open("originFile.txt", O_RDONLY);
        if (fd < 0) {
            perror("open originFile.txt");
            exit(1);
        }

        int wfd = open(fifo1, O_WRONLY);
        if (wfd < 0) {
            perror("open fifo1");
            exit(1);
        }

        char buf[4096];
        ssize_t bytes;
        while ((bytes = read(fd, buf, sizeof(buf))) > 0) {
            if (write(wfd, buf, bytes) != bytes) {
                perror("write to fifo1");
                exit(1);
            }
        }
        close(fd);
        close(wfd);

        // Now read from fifo2 and write to receivedBack.txt
        int rfd = open(fifo2, O_RDONLY);
        if (rfd < 0) {
            perror("open fifo2");
            exit(1);
        }

        fd = open("receivedBack.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
        if (fd < 0) {
            perror("open receivedBack.txt");
            exit(1);
        }

        while ((bytes = read(rfd, buf, sizeof(buf))) > 0) {
            if (write(fd, buf, bytes) != bytes) {
                perror("write to receivedBack.txt");
                exit(1);
            }
        }
        close(rfd);
        close(fd);

        long endTime = getTimeElapsed();
        //compareFiles("originFile.txt", "receivedBack.txt");
        printf(">>> Total round-trip time: %ld ms\n", endTime - startTime);
    }

    return 0;
}
