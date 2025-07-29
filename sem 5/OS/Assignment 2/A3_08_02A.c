/*
>Team: 08 , Date:28/7/25
>Name: Debodit Ray, Roll: 13
>Name: Kaustav Mondal , Roll: 17
>Name: Anuska Nath , Roll: 03

>Assignment description:

SIGNAL Handling 
Catch the signal ‘SIGINT’ and display “Ha Ha, Not Stopping”. Use ‘signal’ system call.
Always use “perror” to check the return status of a library/system call.


>Compilation command : gcc A3_08_02A.c -o A3_exe

>Execution Seq: ./A3_exe

>Output: 

Running... Press Ctrl+C to test
Running... Press Ctrl+C to test
Running... Press Ctrl+C to test
^CHa Ha, Not Stopping
Running... Press Ctrl+C to test
Running... Press Ctrl+C to test
Running... Press Ctrl+C to test
Running... Press Ctrl+C to test
Running... Press Ctrl+C to test
^CHa Ha, Not Stopping
Running... Press Ctrl+C to test

*/
    

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("Ha Ha, Not Stopping\n");
}

int main() {
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    while (1) {
        printf("Running... Press Ctrl+C to test\n");
        sleep(2);
    }

    return 0;
}
