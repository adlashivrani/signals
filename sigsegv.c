#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void signal_handler(int sig);

int main()
{
	pid_t pid;
    signal(SIGSEGV , signal_handler);
    char *str;
    while(1) {
   		str = "hlo";
        *(str+1) = 'n';
        printf("\nInside main\n");
        sleep(1);
    }
    return 0;
}

void signal_handler(int sig)
{
 	printf("%p\n", signal_handler);
//	signal(SIGSEGV,SIG_DFL);
	signal(SIGSEGV,SIG_IGN);
}
