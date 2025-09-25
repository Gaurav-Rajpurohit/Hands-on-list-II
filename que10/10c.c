/*
============================================================================
Name : 10c.c
Author : Gaurav Rajpurohit
Description : 10. Write a separate program using sigaction system call to catch the following signals. 
 c. SIGINT 
Date: Sept 25th, 2025.
============================================================================
*/



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
		
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que10$ cc 10c.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que10$ ./a.out
CAUGHT SIGFPE :8... code == 1 
*/