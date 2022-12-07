#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void main() {
    char* my_env[] = {"USER=ECS501", NULL};    
    
    printf("\n… Before exec: USER=%s\n", getenv("USER"));

    if (execle("changeUser", "changeUser", NULL, my_env)) {
        error("Cannot run changUser");
    }
}    