#include "common.h"

void worker(int fd_read, int fd_write){
	char string[BUFFER_SIZE];
	while(1){
		read(fd_read, string, BUFFER_SIZE);
		if (strcmp(string, "EXIT")==0){
			printf("Program terminated");
			break;
		}
		string[0] = 'X';
		write(fd_write, string, strlen(string));
	}
}
