#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


extern pthread_mutex_t lock;
extern pthread_cond_t cond;
extern int data_ready;

void *worker(void *arg);
void server(int client_socket);

#endif