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

int isBinary(char* msg) {
    printf("%i", strlen(msg));
    for (int i = 0; msg[i] != '\0'; i++) {
        if (msg[i] != '0' && msg[i] != '1') {
            return 0;
        }
    }
    return 1;
}

int power(int i) {
    int j,p=1;
    for(j=1;j<=i;j++)
    p = p*2;
    return(p);
}
int covertBinToDec (long int n) {
    int x,s=0,i=0,flag=1;
    while(flag==1) {
        x=n%10;
        s=s+x*power(i);
        i=i+1;
        n=n/10;
        if(n==0)
        flag=0;
    }
    return s;
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
    
    char buffer[BUFSIZE];
    struct sockaddr_in client_addr;
    socklen_t clientLen = sizeof(client_addr);

    while (1) {
        // recvfrom: receive a UDP datagram from a client
        memset(buffer, 0, BUFSIZE);
        if (recvfrom(serverSocketID, buffer, BUFSIZE, 0, (struct sockaddr*) &client_addr, &clientLen) == -1)
            error("ERROR in recvfrom");

        buffer[strcspn(buffer, "\n")] = '\0';

        struct hostent* hostp;
        hostp = gethostbyaddr((const char*) &client_addr.sin_addr.s_addr, sizeof(client_addr.sin_addr.s_addr), AF_INET);

        if (hostp == NULL)
            error("ERROR on gethostbyaddr");

        char* hostaddrp = inet_ntoa(client_addr.sin_addr);
        if (hostaddrp == NULL) 
            error("ERROR on inet_ntoa\n");
        
        printf("server received datagram from %s (%s) '%s'\n", hostp->h_name, hostaddrp, buffer);

        if (isBinary(buffer) == 1) {
            int binaryValue = covertBinToDec(atol(buffer));
            sprintf(buffer, "Decimal value is %i", binaryValue);
        } else {
            sprintf(buffer, "Not a binary value");
        }

        if (sendto(serverSocketID, buffer, BUFSIZ, 0,
        (struct sockaddr *) &client_addr, clientLen) ==-1)
            error("ERROR in sendto");
    }
}