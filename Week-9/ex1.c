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
    ____________;
    return 0;
}