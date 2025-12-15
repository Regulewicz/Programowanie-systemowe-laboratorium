#include "common.h"

int main(int argc, char *argv[]){
	
	mkfifo(SERV2WORK, 0666);
	mkfifo(WORK2SERV, 0666);
	
	if(argc != 2){
		printf("Wrong amount of arguments\n");
		return 1;
	}
	
	if(strcmp(argv[1], "server")==0){
		printf("S: Waiting\n");
		int fd_write = open(SERV2WORK, O_WRONLY); 
		int fd_read = open(WORK2SERV, O_RDONLY);
		
		printf("S: Connected\n");
		server(fd_read, fd_write);
		
		close(fd_read);
		close(fd_write);
	}
	else if(strcmp(argv[1], "worker")==0){
		printf("W: Wainting\n");
		int fd_read = open(SERV2WORK, O_RDONLY);
		int fd_write = open(WORK2SERV, O_WRONLY);
		
		printf("W: Connected\n");
		worker(fd_read, fd_write);
		
		close(fd_read);
		close(fd_write);	
	}
	else{
		printf("WRONG ARGUMENT NAME\n");
		return 1;
	}
    return 0;
}
