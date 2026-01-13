#ifndef SHARED_H
#define SHARED_H

#include <semaphore.h>

struct shared_data {
    sem_t sem; 
    char text[2048];
};

void server(struct shared_data *data);
void worker(struct shared_data *data);

#endif
