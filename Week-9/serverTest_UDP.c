#include <stdio.h>
/* Headers needed for the socket programming */
#include <sys/types.h> /*define some data types used in system calls */
#include <sys/socket.h> /*definitions of structures needed for sockets */
#include <unistd.h> /* contains various constants */
#include <netinet/in.h>
#include <netdb.h> /* This is needed in UDP servers too */
#include <arpa/inet.h> /* It is needed because inet_ntoa() */
/*constants and structures needed for Internet domain addresses */
#include <errno.h> /* Necessary because errno value used */
#include <string.h> /* Necessary for memset() */
#include <stdlib.h> /* Necessary for exit() */
#define BUFSIZE 1024

/* error - wrapper for perror */
void error(char *msg) {
    perror(msg);
    exit(0);
}

void main(int argc, char* argv[]) {
    int serverSocketID; // server socket file descriptor
    int portNo; // Port to listen on
    struct sockaddr_in serv_addr; // server's addr

    /* check command line arguments */
    if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
    }

    portNo = atoi(argv[1]); // Takes argument in cmd line for the port as interger

    // create server socket
    serverSocketID = socket(PF_INET, SOCK_DGRAM, 0);

    if (serverSocketID < 0) error("ERROR opening socket");

    int optval = 1;
    setsockopt(serverSocketID, SOL_SOCKET, SO_REUSEADDR, (const void *) &optval, sizeof(int));

    memset(&serv_addr,0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portNo);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if (bind(serverSocketID, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) 
        error("ERROR on binding");
    
    int n;
    char buffer[BUFSIZE];
    struct sockaddr_in client_addr;
    socklen_t clientLen = sizeof(client_addr);

    while (1) {
        // recvfrom: receive a UDP datagram from a client
        memset(buffer, 0, BUFSIZE);
        if (recvfrom(serverSocketID, buffer, BUFSIZE, 0, (struct sockaddr*) &client_addr, &clientLen) == -1)
            error("ERROR in recvfrom");

        struct hostent* hostp;
        hostp = gethostbyaddr((const char*) &client_addr.sin_addr.s_addr, sizeof(client_addr.sin_addr.s_addr), AF_INET);

        if (hostp == NULL)
            error("ERROR on gethostbyaddr");

        char* hostaddrp = inet_ntoa(client_addr.sin_addr);
        if (hostaddrp == NULL) 
            error("ERROR on inet_ntoa\n");
        
        printf("server received datagram from %s (%s)\n", hostp->h_name, hostaddrp);

        if (sendto(serverSocketID, buffer, strlen(buffer), 0,
        (struct sockaddr *) &client_addr, clientLen) ==-1)
            error("ERROR in sendto");
    }
}

// void main(int argc, char *argv[]) {
//     int sockid; /* socket */
//     int portno; /* port to listen on */
//     socklen_t clientlen; /* Size of client's address */
//     struct sockaddr_in serveraddr; /* server's addr */
//     struct sockaddr_in clientaddr; /* client addr */
//     struct hostent *hostp; /* client host info */
//     char buf[BUFSIZE]; /* message buf */
//     char *hostaddrp; /* dotted decimal host addr string */
//     int optval; /* flag value for setsockopt */
//     int n; /* message byte size */
//     /* check command line arguments */
//     if (argc != 2) {
//     fprintf(stderr, "usage: %s <port>\n", argv[0]);
//     exit(1);
//     }
//     portno = _________; /* Takes argument in cmd line for the port as interger */
//     /* socket: create the parent socket */
//     sockid = ______(_______, ________, 0);
//     if (sockid < 0)
//     error("ERROR opening socket");
//     /* setsockopt:
//     * Handy debug trick that lets rerun the server immediately after being killed;
//     * otherwise one needs to wait about 20 secs.
//     * Eliminates "ERROR on binding: Address already in use" error.
//     */
//     optval = 1;
//     setsockopt(sockid, SOL_SOCKET, SO_REUSEADDR,
//     (const void *)&optval , sizeof(int));
//     /* build the server's Internet address */
//     memset(&serveraddr,0, sizeof(serveraddr));
//     serveraddr.sin_family = ________;
//     serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
//     serveraddr.sin_port = htons(_______);
//     /* bind: associate the parent socket with a port */
//     if (____(sockid, _______________, _________) < 0)
//     error("ERROR on binding");
//     /* build the server's Internet address */
//     memset(&serveraddr,0, sizeof(serveraddr));
//     serveraddr.sin_family = ________;
//     serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
//     serveraddr.sin_port = htons(_______);
//     /* bind: associate the parent socket with a port */
//     if (____(sockid, _______________, _________) < 0)
//     error("ERROR on binding");
//     /* build the server's Internet address */
//     memset(&serveraddr,0, sizeof(serveraddr));
//     serveraddr.sin_family = ________;
//     serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
//     serveraddr.sin_port = htons(_______);
//     /* bind: associate the parent socket with a port */
//     if (____(sockid, _______________, _________) < 0)
//     error("ERROR on binding");
//     /*
//     * sendto: echo the input back to the client
//     */
//     n = sendto(sockid, buf, strlen(buf), 0,
//     (struct sockaddr *) &clientaddr, clientlen);
//     if (n < 0)
//     error("ERROR in sendto");
// }