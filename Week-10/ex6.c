#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#define NUM_OF_THREADS 15

int count = 0;

void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;

void* worker() {
    pthread_mutex_lock(&count_lock);   
    for (int i = 0; i < 1000000; i++) {
        count++;
    }
    pthread_mutex_unlock(&count_lock);   
    return NULL;
}

void main() {
    pthread_t threads[NUM_OF_THREADS];
    void* result;

    for (long i = 0; i < NUM_OF_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, worker, (void*)i) == -1) {
            error("Cannot create thread");       
        }
    }

    for (long i = 0; i < NUM_OF_THREADS; i++) {
        if (pthread_join(threads[i], &result) == -1) {
            error("Cannot join thread");
        }
    }
    
    printf("%i", count);
}