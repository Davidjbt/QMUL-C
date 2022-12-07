#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game(int sig){
	printf("\nFinal score: %i\n", score);
	exit(0);
}

int catch_signal(int sig, void (*handler)(int)) {
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}

void times_up(int sig) {
	puts("\nTIME'S UP!");
	raise(SIGINT);
}

void error(char *msg) {
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

void testPalindrome(int len) {
	char s[len];
	int i,j;
	printf("Enter a word of length %d:\n",len);
	fflush(stdin);
	gets(s);
	for (i=0,j=len-1;i<j;i++,j--){
		if (s[i]!=s[j]){
			printf("\nNot a Palindrome\n");
			raise(SIGINT);
			break;
		} else
			printf("\nPalindrome\n");
	}
}

void main() {
	int len = 3; // length of the palidrome word to be entered.
	int seconds = 20; // amount of period in which the user has to answer.
	
	catch_signal(SIGALRM, times_up);
	catch_signal(SIGINT, end_game);
	
	while (1) {
		alarm(seconds);
		testPalindrome(len);
		score++;
		len++;
		seconds += 10;
	}
}