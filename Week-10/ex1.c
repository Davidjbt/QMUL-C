#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void runChild(void) {
 printf("\nI am the child! My pid is %d\n",getpid());
}

void main() {
	pid_t pid = fork();
	
	if (pid == 0) {
		runChild();
	} else if (pid > 0){
		sleep(5);
		printf("I'm still here!\n");		
	} else {
		printf("The creation of a child process was unsuccessful.\n");	
	}
}