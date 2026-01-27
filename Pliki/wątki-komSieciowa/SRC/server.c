#include "common.h"

void server(int client_socket){
    char buffer[2049];
    memset(buffer, 0, sizeof(buffer));

    recv(client_socket, buffer, 2048, 0);

    buffer[strcspn(buffer, "\r\n")] = 0;

    if (strcmp(buffer, "EXIT") == 0){
        close(client_socket);
        exit(0);
    }

    pthread_t worker_thread;
    pthread_create(&worker_thread, NULL, worker, (void *)buffer);
    
    pthread_mutex_lock(&lock);
    data_ready = 1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);

    pthread_join(worker_thread, NULL);

    char response[2049];
    snprintf(response, sizeof(response), "%s", buffer);
    send(client_socket, response, strlen(response), 0);
}