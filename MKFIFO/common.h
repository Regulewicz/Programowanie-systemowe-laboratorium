#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SERV2WORK "/home/regul/Desktop/MKFIFO/serv2work" 
#define WORK2SERV "/home/regul/Desktop/MKFIFO/work2serv"

void server(int fd_read, int fd_write);
void worker(int fd_read, int fd_write);

#define BUFFER_SIZE 256

#endif
