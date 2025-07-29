/*
>Team: 08 , Date:22/7/25
>Name: Debodit Ray, Roll: 13
>Name: Kaustav Mondal , Roll: 17
>Name: Anuska Nath , Roll: 3

>Assignment description:


Problem Definition: 
Program to GET and SET the Environment variable and to know the use of getenv and setenv system calls

UNIX ENVIRONMENT VARIABLES:
Variables are a way of passing information from the shell to programs when you run them.
Programs look "in the environment" for particular variables and if they are found will use the
values stored. Some are set by the system, others by you, yet others by the shell, or any program
that loads another program. Standard UNIX variables are split into two categories, environment
variables and shell variables. In broad terms, shell variables apply only to the current instance of
the shell and are used to set short-term working conditions; environment variables have a farther
reaching significance, and those set at login are valid for the duration of the session. By
convention, environment variables have UPPER CASE and shell variables have lower case
names.

Display the following environment variables using getenv call:
∙ USER (your login name)
∙ HOME (the path name of your home directory)
∙ HOST (the name of the computer you are using)
∙ ARCH (the architecture of the computer's processor)
∙ DISPLAY (the name of the computer screen to display X windows)
∙ PRINTER (the default printer to send print jobs)
∙ PATH (the directories the shell should search to find a command)

Syntax: Char *getenv( const char *name);

The getenv() function searches the environment list to find the Environment variable name,
and returns a pointer to the corresponding value string.
Now, Set two new environment variables and display them.
Syntax: int setenv(const char * envname,const char * enval,int overwrite)
The setenv() function adds the variable name to the environment with the value value, if name
does not already exist. If name does exist in the environment, then its value is changed to value
if overwrite is nonzero; if overwrite is zero, then the value of name is not changed (and
setenv() returns a success status).

Note: make sure you don't modify the already generated system’s environment variable like
HOME, HOST etc.



>Compilation command : gcc A3_08_01B.c -o A3_exe

>Execution Seq: ./A3_exe IT UG3

>Sample Input : IT UG3 (in CLI)


>Output:

Displaying Pre-existing Environment Variables:
---------------------------------------------
USER: be2313
HOME: /home/usr/student/ug/yr23/be2313
HOST: Not found (May not be directly set as an environment variable)
ARCH: Not found (May not be directly set as an environment variable)
DISPLAY: Not found
PRINTER: Not found
PATH: /usr/lib64/qt-3.3/bin:/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin

Setting New Environment Variables with CLI Arguments:
-----------------------------------------------------
DEPARTMENT set successfully to "IT".
CLASS set successfully (or not overwritten if already existed) to "UG3".

Displaying newly set variables immediately after setting:
-------------------------------------------------------
DEPARTMENT: IT
CLASS: UG3

Demonstrating 'overwrite' parameter:
------------------------------------
Attempting to set DEPARTMENT with overwrite=0 (value should NOT change from "IT"):
setenv call successful (but value may not have changed due to overwrite=0).
DEPARTMENT (after no-overwrite attempt): IT

Attempting to set DEPARTMENT with overwrite=1 (value SHOULD change):
setenv call successful.
DEPARTMENT (after overwrite attempt): OverwrittenDepartment

*/


#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <DEPARTMENT> <CLASS>\n", argv[0]);
        return 1;
    }

    const char *input_department = argv[1];
    const char *input_class = argv[2];

    //displaying Existing Environment Variables ---
    printf("Displaying Pre-existing Environment Variables:\n");
    printf("---------------------------------------------\n");

    char *val;

    val = getenv("USER");
    printf("USER: %s\n", val ? val : "Not found");

    val = getenv("HOME");
    printf("HOME: %s\n", val ? val : "Not found");

    val = getenv("HOST");
    printf("HOST: %s\n", val ? val : "Not found (May not be directly set as an environment variable)");

    val = getenv("ARCH");
    printf("ARCH: %s\n", val ? val : "Not found (May not be directly set as an environment variable)");

    val = getenv("DISPLAY");
    printf("DISPLAY: %s\n", val ? val : "Not found");

    val = getenv("PRINTER");
    printf("PRINTER: %s\n", val ? val : "Not found");

    val = getenv("PATH");
    printf("PATH: %s\n", val ? val : "Not found");

    printf("\n");

    //setting New Environment Variables from CLI Args ---
    printf("Setting New Environment Variables with CLI Arguments:\n");
    printf("-----------------------------------------------------\n");

    if (setenv("DEPARTMENT", input_department, 1) != 0) {
        perror("Failed to set DEPARTMENT");
    } else {
        printf("DEPARTMENT set successfully to \"%s\".\n", input_department);
    }

    if (setenv("CLASS", input_class, 0) != 0) {
        perror("Failed to set CLASS");
    } else {
        printf("CLASS set successfully (or not overwritten if already existed) to \"%s\".\n", input_class);
    }

    printf("\nDisplaying newly set variables immediately after setting:\n");
    printf("-------------------------------------------------------\n");

    val = getenv("DEPARTMENT");
    printf("DEPARTMENT: %s\n", val ? val : "Not found");

    val = getenv("CLASS");
    printf("CLASS: %s\n", val ? val : "Not found");

    //demonstrating the 'overwrite' parameter of setenv ---
    printf("\nDemonstrating 'overwrite' parameter:\n");
    printf("------------------------------------\n");

    val = getenv("DEPARTMENT");
    printf("Attempting to set DEPARTMENT with overwrite=0 (value should NOT change from \"%s\"):\n", val ? val : "N/A");
    if (setenv("DEPARTMENT", "NewDepartmentValue", 0) != 0) {
        perror("Failed to attempt setting DEPARTMENT with overwrite=0");
    } else {
        printf("setenv call successful (but value may not have changed due to overwrite=0).\n");
    }

    val = getenv("DEPARTMENT");
    printf("DEPARTMENT (after no-overwrite attempt): %s\n", val ? val : "Not found");

    printf("\nAttempting to set DEPARTMENT with overwrite=1 (value SHOULD change):\n");
    if (setenv("DEPARTMENT", "OverwrittenDepartment", 1) != 0) {
        perror("Failed to attempt setting DEPARTMENT with overwrite=1");
    } else {
        printf("setenv call successful.\n");
    }

    val = getenv("DEPARTMENT");
    printf("DEPARTMENT (after overwrite attempt): %s\n", val ? val : "Not found");

    return 0;
}
