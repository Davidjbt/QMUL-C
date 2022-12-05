#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main() {
    // try to run the "/sbin/ifconfig" program firstly
    if (execl("/sbin/ifconfig", "/sbin/ifconfig",NULL)){
    // if failed, try the ipconfig command
        if (execlp("ipconfig", "ipconfig", NULL)){
            fprintf(stderr,"Cannot run ipconfig: %s",strerror(errno));
            return 1;
        }
    }
    return 0;
}