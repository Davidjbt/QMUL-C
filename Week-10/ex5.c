#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#define NUM_OF_THREADS 15

void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void* worker() {

}

void main() {
    pthread_t threads[NUM_OF_THREADS];

    for (int i = 0; i < NUM_OF_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, worker, (void*)i) == -1) {
            
        }
        
    }
    



}