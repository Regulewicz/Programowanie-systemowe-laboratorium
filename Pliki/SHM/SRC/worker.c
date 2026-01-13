#include <stdio.h>
#include <string.h>
#include "shared.h"

void worker(struct shared_data *data) {
    while (1) {
        sem_wait(&data->sem);

        if (strcmp(data->text, "EXIT") == 0) {
            sem_post(&data->sem);
            break;
        }

        data->text[0] = 'X';
	sem_post(&data->sem);
    }
}

