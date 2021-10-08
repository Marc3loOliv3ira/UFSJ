#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	int fd[2];
	pid_t childp;

	if(pipe(fd) == -1){
		perror("Error pipe");
		exit(1);
	}

	if((childp = fork()) == -1){
		perror("Error fork");
		exit(1);
	}
	if(childp == 0){
		char comando;
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execlp("./process_manager", "", NULL);
	}else{
		close(fd[0]);
		char comando;
	while(comando != 'T'){
            scanf("%c", &comando);
            write(fd[1], &comando, sizeof(char));
						sleep(1);
}
	}
	wait(0);
}
