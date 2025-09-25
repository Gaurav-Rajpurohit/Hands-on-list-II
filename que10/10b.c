
/*
============================================================================
Name : 10a.c
Author : Gaurav Rajpurohit
Description : 10. Write a separate program using sigaction system call to catch the following signals. 
 b. SIGINT 
Date: Sept 25th, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void func(int sig, siginfo_t *si, void *unused){
	printf("  `CAUGHT SIGFPE : signal is %d....\n", sig);
	fflush(stdout);
}

int main(){
	struct sigaction s;

	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = func;
	sigemptyset(&s.sa_mask);


	sigaction(SIGINT,&s, NULL);

	printf("RUNNIG.. CTRL+C to send SIGINT .... \n");

	while(1) pause();
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que10$ cc 10b.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que10$ ./a.out
RUNNIG.. CTRL+C to send SIGINT .... 
^C  `CAUGHT SIGFPE : signal is 2....
^C  `CAUGHT SIGFPE : signal is 2....
^C  `CAUGHT SIGFPE : signal is 2....
^C  `CAUGHT SIGFPE : signal is 2....
*/