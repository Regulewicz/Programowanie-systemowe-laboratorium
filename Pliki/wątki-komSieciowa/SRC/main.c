#include "common.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int data_ready = 0;

int main(){
    int serverfd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int opt = 1;

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
   
    setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    bind(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(serverfd, 5);

    while(1){
        client_socket = accept(serverfd, (struct sockaddr *)&client_addr, &addr_len);
        server(client_socket);
    }

    close(serverfd);
    return 0;
}