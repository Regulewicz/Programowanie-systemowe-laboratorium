#include<stdio.h>
#include<string.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){
	char napis[256];
	char napis2[256];
	int fd[2];
	pid_t pid;
	pipe(fd);
	if(pipe(fd) == -1){
		printf("Error 1 ");
		return 1;
	}	
	pid = fork();

	if(pid==0){
		close(fd[0]);	
		printf("Podaj stringa");
		scanf("%s",napis);
		napis[0] = 'X';
		write(fd[1], napis, strlen(napis)+1);
		close(fd[1]);
	}

	if(pid > 0){
		close(fd[1]);
		wait(NULL);
		read(fd[0], napis2, 256);
		printf("Przerobiony string: %s", napis2);
		close(fd[0]);
	}
	
	else{
		return 1;
	}

	return 0;
}
