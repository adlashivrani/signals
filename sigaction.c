#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) 
{
	if (signum == SIGINT) {
		printf("SIGINT\n");
		
	}
}
/*
void handler1(int signum)
{
	if (signum == SIGQUIT) {
		printf("SIGQUIT\n");
	}
}*/

int main()
{
	struct sigaction sa;
//	sa.sa_handler = SIG_DFL;
//	sa.sa_handler = SIG_IGN;
	sa.sa_handler = handler;
//	struct sigaction sa1;
//	sa1.sa_handler = handler1;
	
	while (1) {
		printf("Hi\n");
		sleep(1);
		//raise(SIGQUIT);
		/*if (sigaction(SIGQUIT, &sa,NULL) == -1) {*/
		if (sigaction(SIGINT , &sa,NULL) == -1) {
			printf("SIGACTION\n");
			exit(1);
		}
	}
	return 0;
}
