/*
============================================================================
Name : 8b.c
Author : Gaurav Rajpurohit
Description : 8. Write a separate program using signal system call to catch the following signals.  
b. SIGINT 
Date: Sept 25th, 2025.
============================================================================
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>


void fun(int sig){
	printf("Caught SIGINT signal :%d\n", sig);
	fflush(stdout);
}

int main(){
	signal(SIGINT, fun);

	printf("Program is running... press Ctrl + C to send signals... SIGINT means Interrupt signals ... \n");

	while(1)
		pause();

	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ cc 8b.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ ./a.out
Program is running... press Ctrl + C to send signals... SIGINT means Interrupt signals ... 
^CCaught SIGINT signal :2
^CCaught SIGINT signal :2

*/