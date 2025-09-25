/*
============================================================================
Name : 8f.c
Author : Gaurav Rajpurohit
Description : 8. Write a separate program using signal system call to catch the following signals.  
f. SIGVTALRM (using setitimer system call)
Date: Sept 25th, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>


void fun(int sig){
	printf("CAUGHT signal SIGALRM : %d\n ", sig);
	fflush(stdout);
}


int main(){
	struct itimerval t;

	signal(SIGVTALRM, fun);

	t.it_value.tv_sec = 1;
	t.it_value.tv_usec = 0;
	t.it_interval.tv_sec= 2;
	t.it_interval.tv_usec = 0;

	setitimer(ITIMER_VIRTUAL, &t, NULL);

	printf("Virtual TImer starts after 1 sec of CPU time , then every 2secs of CPU time .. \n");
	
	while(1){
	for(long i = 0; i<10000000 ;i++);
	}

return 0;
}

		
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ vim 8f.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ cc 8f.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ ./a.out
Virtual TImer starts after 1 sec of CPU time , then every 2secs of CPU time .. 
CAUGHT signal SIGALRM : 26
 CAUGHT signal SIGALRM : 26
 CAUGHT signal SIGALRM : 26
 CAUGHT signal SIGALRM : 26
 CAUGHT signal SIGALRM : 26
 CAUGHT signal SIGALRM : 26
 ^Z
[11]+  Stopped                 ./a.out
*/