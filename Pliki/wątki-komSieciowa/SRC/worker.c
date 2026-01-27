#include "common.h"

void *worker(void *arg){
    char *buffer = (char *)arg;

    pthread_mutex_lock(&lock);
    
    while (data_ready == 0){
        pthread_cond_wait(&cond, &lock);
    }

    if(strlen(buffer) > 0) {
        buffer[0] = 'X';
    }

    data_ready = 0;

    pthread_mutex_unlock(&lock);
    return NULL;
}
