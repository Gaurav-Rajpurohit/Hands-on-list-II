/*
============================================================================
Name : 3.c
Author : Gaurav Rajpurohit
Description : 3. Write a program to set (any one) system resource limit. Use setrlimit system call.  
Date: Sept 21st, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>

int main(){
	struct rlimit r;

	r.rlim_cur = 5;
	r.rlim_max = 10;

	setrlimit(RLIMIT_CPU, &r);

	printf("CPU softlimit is set to :%ld and hard limit set to :%ld \n", r.rlim_cur, r.rlim_max);

	printf("lets check its working or not\n");

	long long i = 0;
	while(1){
		i++;
	}

	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que3$ cc 3.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que3$ ./a.out
CPU softlimit is set to :5 and hard limit set to :10 
lets check its working or not
CPU time limit exceeded (core dumped)

*/