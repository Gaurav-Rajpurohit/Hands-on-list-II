/*
============================================================================
Name : 8d.c
Author : Gaurav Rajpurohit
Description : 8. Write a separate program using signal system call to catch the following signals.  
d. SIGALRM 
Date: Sept 25th, 2025.
============================================================================
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void fun(int sig){
	printf("Alarm signal send and its SIGALRM number is :%d\n ", sig);
	fflush(stdout);
	exit(0);
}

int main(){
	signal(SIGALRM, fun);

	printf("Setting alarm for 10 seconds\n");


	alarm(5);

	while(1) pause();

	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ cc 8d.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ ./a.out
Setting alarm for 10 seconds
Alarm signal send and its SIGALRM number is :14
*/