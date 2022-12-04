#include <stdio.h>
/* Headers needed for the socket programming */
#include <sys/types.h> /*define some data types used in system calls */
#include <sys/socket.h> /*definitions of structures needed for sockets */
#include <unistd.h> /* contains various constants */
#include <netinet/in.h>
/*constants and structures needed for Internet domain addresses */
#include <errno.h> /* Necessary because errno value used */
#include <string.h> /* Necessary for bzero() */
#include <stdlib.h> /* Necessary for exit() */
#include <time.h>
// This function returns a string containing the current date and time
char* now() {
    time_t t;
    time (&t);
    return asctime(localtime(&t));
}

void error(char* msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void main(int argc, char* argv[]) {
    int serverSocketID; // server socket file descriptor
    int portNo;
    struct sockaddr_in serv_addr;

    if (argc < 2) error("No port provided in cmd line");

    serverSocketID = socket(PF_INET, SOCK_STREAM, 0);

    if (serverSocketID == -1) error("Cannot open listening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    portNo = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portNo);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(serverSocketID, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) error("Can't bind to server socket");

    if (listen(serverSocketID, 1) == -1) error("Cannot listen");

    struct sockaddr_in client_addr;
    socklen_t clientLen = sizeof(client_addr);
    int clientSocketID = accept(serverSocketID, (struct sockaddr*) &client_addr, &clientLen);

    char msg[256];
    char msgToClient[256];

    if (read(clientSocketID, msg, 255) == -1) error("Server cannot write to client socket");

    msg[strcspn(msg, "\n")] = '\0';
    printf("Message from client: %s\n", msg);
    
    
    if (strcmp(msg, "/Time") == 0) {
        strlcpy(msgToClient, now(), sizeof(msgToClient));
    } else {
        strlcpy(msgToClient, "Not a time command.", sizeof(msgToClient));
    }

    if (write(clientSocketID, msgToClient, sizeof(msgToClient)) == -1) error("Server cannot write to client socket");

    printf("Closing server...");

    close(clientSocketID);
    close(serverSocketID);
}

