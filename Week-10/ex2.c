#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void runChild(void) {
	printf("\nI am the child! My pid is %d\n", getpid());
}

void main() {
	pid_t pid = fork();
	int status;
	
	if (pid == 0) {
		runChild();
	} else if (pid > 0){
		wait(&status);
		printf("I'm still here!\n");		
		printf("Child process exit status: %i\n", WEXITSTATUS(status));
	} else {
		printf("The creation of a child process was unsuccessful.\n");	
	}
}