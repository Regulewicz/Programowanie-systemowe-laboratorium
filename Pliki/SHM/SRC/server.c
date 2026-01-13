#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "shared.h"

void server(struct shared_data *data) {
    sem_init(&data->sem, 1, 1);

    while (1) {

        sem_wait(&data->sem);
        printf("Podaj tekst: ");
        scanf("%s", data->text);
        if (strcmp(data->text, "EXIT") == 0) {
            sem_post(&data->sem);
            break;
        }

        sem_post(&data->sem);
	
	usleep(1000);

        sem_wait(&data->sem);

        printf("Przerobiony tekst: %s\n", data->text);
        sem_post(&data->sem);
    }
}

