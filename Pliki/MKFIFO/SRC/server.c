#include "common.h"

void server(int fd_read, int fd_write){
	char string[BUFFER_SIZE];
	while (1) {
		printf("Enter a string or enter 'EXIT' to end program: ");
		scanf("%s", string);
		write(fd_write, string, strlen(string)); 
		if(strcmp(string, "EXIT") == 0) {	
			printf("Program terminated\n");
			break;
		}
		read(fd_read, string, BUFFER_SIZE);
		printf("Modified string: %s\n", string);
	}
}
