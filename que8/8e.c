/*
============================================================================
Name : 8e.c
Author : Gaurav Rajpurohit
Description : 8. Write a separate program using signal system call to catch the following signals.  
e. SIGALRM (using setitimer system call)
Date: Sept 25th, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
#include<signal.h>

void fun(int sig){
	printf("SIGALRM : %d\n",sig);
	fflush(stdout);

	
}


int main(){
	struct itimerval t;

	signal(SIGALRM, fun);

	t.it_value.tv_sec = 2;
	t.it_value.tv_usec = 0;
	t.it_interval.tv_sec = 2;
	t.it_interval.tv_usec = 0;

	setitimer(ITIMER_REAL, &t, NULL);

	printf("Timer started in 2 seconds and interval is 2 seconds .. \n");

	while(1)
		pause();

	return 0;
}
	
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ cc 8e.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ ./a.out
Timer started in 2 seconds and interval is 2 seconds .. 
SIGALRM : 14
SIGALRM : 14
SIGALRM : 14
*/
