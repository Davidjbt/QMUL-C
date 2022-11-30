#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// This function returns a string containing the current date and time
char* now() {
    time_t t;
    time (&t);
    return asctime(localtime(&t));
}
// Master Control Program utility. Records guard patrol check-ins.
int main() {
    char comment[80];
    char cmd[120];
    printf("Enter your name and patrol password: ");
    fgets(comment,80,stdin);
    sprintf(cmd,"echo '%s %s'>>reports.log",comment,now());
    system(cmd);
    return 0;
}
// 1. echo is a Unix/Linux command that takes a string as argument to output to the screen, by using the '>>', the string is written on the reports.log file. '%s %s' will collect 2 strings, comment and the value returned by now(). So cmd will have a Linux command, echo with 2 strings between single quotes as paramater.
// 2. Creates a variable for storing the calendar time. time() calculates the current date and localtime  breaks it into some structure that asctime will use to form a string which represents the day and time of it.
// 3. '>>' is used for appending the output in the file, and '>' is used for overwrite the contents of the file with the output.