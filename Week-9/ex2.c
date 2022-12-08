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

#define NUM_OF_CLIENTS 5

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

    if (listen(serverSocketID, NUM_OF_CLIENTS) == -1) error("Cannot listen");

    for (int i = 0; i < NUM_OF_CLIENTS; i++) {
        struct sockaddr_in client_addr;
        socklen_t clientLen = sizeof(client_addr);
        int clientSocketID = accept(serverSocketID, (struct sockaddr*) &client_addr, &clientLen);

        char msg[256];

        if (read(clientSocketID, msg, 255) == -1) error("Server cannot write to client socket");

        printf("Messaga from client %i: %s", i + 1, msg);

        if (write(clientSocketID, msg, sizeof(msg)) == -1) error("Server cannot write to client socket");

        
        close(clientSocketID);
    }
    printf("Limit of requests (%i) reached, closing server...", NUM_OF_CLIENTS);

    close(serverSocketID);
}

// void main(int argc, char *argv[]) {
//     int sockid, clientSockid; /* socket file descriptors */
//     int portno; /* port number on which the server accepts connections */
//     socklen_t clientLen;
//     int n;
//     char buffer[256]; /* server reads characters from the socket into this buffer */
//     /* socket structures for the Internet addresses*/
//     struct sockaddr_in serv_addr, cli_addr;
//     if (argc < 2) error("No port provided in cmd line");
//     /*creates a stream socket that belongs to the INTERNET family */
//     sockid = socket(PF_INET, SOCK_STREAM, 0);
//     if (sockid == -1) error("Cannot open listening socket");
//     bzero((char *) &serv_addr, sizeof(serv_addr)); /*sets all values to zero */
//     portno = atoi(argv[1]);
//     /* setting the individual fields of the sockaddr_in structure */
//     serv_addr.sin_family = AF_INET;
//     serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
//     serv_addr.sin_port = htons(portno); /* converts to big-endian if necessary */
//     /*binds socket to the address of the current host and port number on which the
//     server will run */
//     if (bind(sockid, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
//     error("Cannot bind to listening socket");
//     /* listen on the socket for connections with a backlog queue of 5 */
//     if (listen(sockid, 5) == -1) error("Cannot listen");
//     /*accept() causes the process to block until a client connects to the server */
    
//     for (int i = 0; i < 5; i++) {
        
//     }
    
    
//     clientLen = sizeof(cli_addr);
//     clientSockid = accept (sockid, (struct sockaddr *) &cli_addr, &clientLen);
//     if (clientSockid == -1) error("Server cannot accept client socket");
//     /*client has successfully connected to our server */
//     /* buffer is initialised and then server reads from the client socket descriptor */
//     bzero(buffer, 256);
//     n = read(clientSockid,buffer,255); /* read() blocks until something to read */
//     if (n == -1) error("Server cannot read from client socket");
//     printf("Here is the message: %s\n",buffer);
//     /*Once a connection has been established, both ends can both read and write to
//     the connection */
//     /* simply writes a short message to the client */
//     n = write(clientSockid,"I got your message",18);
//     if (n == -1) error("Server cannot write to client socket");
//     /* Closing sockets before ending main */
//     close(sockid);
//     close(clientSockid);
// }