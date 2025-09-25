#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void funct(int sig, siginfo_t  *si, void *unused){
	printf("CAUGHT SIGFPE :%d... code == %d \n", sig, si -> si_code);
	fflush(stdout);
	exit(1);
}

int main(){
	struct sigaction s;

	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = funct;
	sigemptyset(&s.sa_mask);

	sigaction(SIGFPE, &s, NULL);


	int a = 10;

	int b =  0;
	int c = a / b;

	return 0;
}
		
