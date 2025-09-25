

/*
============================================================================
Name : 8a.c
Author : Gaurav Rajpurohit
Description : 8. Write a separate program using signal system call to catch the following signals.  
a. SIGSEGV 
Date: Sept 25th, 2025.
============================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void handler(int sig){
	printf("SIGSEGV got caught:%d\n", sig);
	exit(1);
	}

int main(){
	signal(SIGSEGV, handler);
	int  *i = NULL;
	*i =1;
	return 0;

}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ vim 8a.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ cc 8a.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que8$ ./a.out
SIGSEGV got caught:11
*/
