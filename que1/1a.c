/*
============================================================================
Name : 1a.c
Author : Gaurav Rajpurohit
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and  10micro second 
 a. ITIMER_REAL 

Date: Sept 21st, 2025.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>

void somefunc(int sig){
	printf("Let me do my work!!!:\n");
}
int main(){

	struct itimerval tim;

	signal(SIGALRM, somefunc);

	tim.it_value.tv_sec = 10;
	tim.it_value.tv_usec = 10;
	tim.it_interval.tv_sec = 10;
	tim.it_interval.tv_sec = 10;

	setitimer(ITIMER_REAL, &tim, NULL);

	while(1);
	return 0;
}

/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que1$ vim 1a.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que1$ cc 1a.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que1$ ./a.out
Let me do my work!!!
Let me do my work!!!
Let me do my work!!!
Let me do my work!!!
*/
