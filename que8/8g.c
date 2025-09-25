/*
============================================================================
Name : 8g.c
Author : Gaurav Rajpurohit
Description : 8. Write a separate program using signal system call to catch the following signals.  
g. SIGPROF 
Date: Sept 25th, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/time.h>

void fun(int sig){
	printf("sigprof : %d\n ", sig);
	fflush(stdout);
}

int main(){

	struct itimerval t;

	signal(SIGPROF, fun);
	
	t.it_value.tv_sec = 2;
	t.it_value.tv_usec = 0;
	t.it_interval.tv_sec = 1;
	t.it_interval.tv_usec = 0;


	setitimer(ITIMER_PROF, &t, NULL);

	printf("Profile timer starts after  2 sec and then after every interval of 1 sec.. \n");

	while(1){

		for(long i = 0; i<1000000;i++);
		write(STDOUT_FILENO, "", 0);

	}
		return 0;
}

/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ ./a.out
Profile timer starts after  2 sec and then after every interval of 1 sec.. 
sigprof : 27
 sigprof : 27
 sigprof : 27
 sigprof : 27
 sigprof : 27
 ^Z
[14]+  Stopped                 ./a.out
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ 

*/