#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	//signal(SIGSEGV , signal_handler);
    char *str;
   	while(1) {
    	str = "hlo";
        *(str+1) = 'n';
		raise(SIGSEGV);
        printf("\nInside main\n");
    }
    return 0;
}

