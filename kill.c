#include<stdio.h>
#include <unistd.h>
#include<signal.h>

void sig_handler(int sig){
 // 	printf("Inside function\n");
//	signal(SIGUSR1, SIG_IGN);
	raise(SIGKILL);	

}

int main()
{
	pid_t pid;
  //signal(SIGUSR1 , sig_handler); // Register signal handler
	signal(SIGUSR1 , sig_handler); 
	while(1) {
  	printf("Inside main function111\n");
  	pid = getpid();      //process id
	printf("pid: %d\n", pid);
  	//kill(pid , SIGKILL);   
	kill(pid , SIGUSR1);
  	printf("Inside main function222\n");
	}
  	return 0;
}
