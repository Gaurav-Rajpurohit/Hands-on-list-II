/*
============================================================================
Name : 10a.c
Author : Gaurav Rajpurohit
Description : 10. Write a separate program using sigaction system call to catch the following signals. 
 a. SIGSEGV 
Date: Sept 25th, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


void fun(int sig, siginfo_t *si, void *unused){
	printf("CAUGHT SIGSEGV :signal %d and address is %p \n", sig, si -> si_addr);
	fflush(stdout);
	exit(1);
}

int main(){
	struct sigaction s;
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = fun;
	sigemptyset(&s.sa_mask);

	sigaction(SIGSEGV, &s, NULL);

	int *p = NULL;
	*p = 54;

	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que10$ cc 10.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que10$ ./a.out
CAUGHT SIGSEGV :signal 11 and address is (nil) 
*/