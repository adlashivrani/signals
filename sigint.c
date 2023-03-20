#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void signal_handler(int sig);

int main()
{
	signal(SIGINT, signal_handler);
    for (int i = 1;;i++) {
    	printf("\nInside main\n");
        sleep(1);
    }
   	return 0;
}

void signal_handler(int sig)
{
	printf("\nInside function\n");
	signal(SIGINT,SIG_DFL);
}

