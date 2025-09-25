/*
============================================================================
Name : 8c.c
Author : Gaurav Rajpurohit
Description : 8. Write a separate program using signal system call to catch the following signals.  
c. SIGFPE 
Date: Sept 25th, 2025.
============================================================================
*/


#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void fun(int sig){
	printf("SIGFPE : %d\n", sig);
	fflush(stdout);
	exit(1);
}	

int main(){
	signal(SIGFPE, fun);

	int a = 10;
	int b = 0;
	printf("Attempting to dividing by zero .. \n");	
	int c = a / b;
	printf("c : %d\n", c);
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ cc 8c.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ ./a.out
Attempting to dividing by zero .. 
SIGFPE : 8
*/