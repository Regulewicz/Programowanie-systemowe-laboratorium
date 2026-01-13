#include<stdio.h>
#include<string.h>
#include <sys/wait.h>
#include <unistd.h>




void server(int fd[2], int fd2[2]){
	char napis[256];

	close(fd[0]);
	close(fd2[1]);
	while (1){
		printf("Enter a string");
		scanf("%s", napis);
		write(fd[1], napis, strlen(napis) + 1);
		if(strcmp(napis, "EXIT") == 0) break;
		read(fd2[0], napis, 256);
		printf("Modified string: %s\n", napis);		
	}
	wait(NULL);
}

void worker(int fd[2], int fd2[2]){
	char napis[256];
	close(fd[1]);
	close(fd2[0]);
	
	while (1){
		read(fd[0], napis, 256);
		if(strcmp(napis, "EXIT") == 0) break;
		napis[0] = 'X';
		write(fd2[1], napis, strlen(napis)+1);	
	}
}





int main(){
	
	int fd[2];
	int fd2[2];

	pid_t pid;
	if(pipe(fd) == -1){
		printf("Error");
		return 1;
	}

	if(pipe(fd2) == -1){
		printf("Error");
		return 1;
	}

	pid = fork();

	if(pid>0){
		server(fd,fd2);
	}	
	if(pid==0){
		worker(fd, fd2);
	}
	return 0;
}
