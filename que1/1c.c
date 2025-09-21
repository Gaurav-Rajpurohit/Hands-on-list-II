/*
============================================================================
Name : 1c.c
Author : Gaurav Rajpurohit
Description : 1. Write a separate program (for each time domain) to set a interval timer in 10sec and  10micro second 
 c. ITIMER_PROF

Date: Sept 21st, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>

void cricket(int sig){
	printf("India won the match !!\n");
}

int main(){
	
	struct itimerval tim;

	signal(SIGPROF, cricket);

	tim.it_value.tv_sec = 10;
	tim.it_value.tv_usec = 10;
	tim.it_interval.tv_sec = 10;
	tim.it_interval.tv_usec = 10;

	setitimer(ITIMER_PROF, &tim, NULL);

	while(1);

	return 0;
}
/*OUTPUT 
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que1$ cc 1c.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que1$ ./a.out
India won the match !!
India won the match !!
*/