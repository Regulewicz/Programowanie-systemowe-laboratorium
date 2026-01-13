#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include "shared.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Error: Zla liczba argumentow\n");
        return 1;
    }

    const char* shm_name = "/IPC";
    int fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(struct shared_data));
    struct shared_data *data = mmap(NULL, sizeof(struct shared_data), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (strcmp(argv[1], "server") == 0) {
        server(data);
        shm_unlink(shm_name);
    } else if (strcmp(argv[1], "worker") == 0) {
        worker(data);
    }

    munmap(data, sizeof(struct shared_data));
    close(fd);
    return 0;
}
