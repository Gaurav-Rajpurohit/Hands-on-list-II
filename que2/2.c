/*
============================================================================
Name : 2.c
Author : Gaurav Rajpurohit
Description : 2. Write a program to print the system resource limits. Use getrlimit system call.  

Date: Sept 21st, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>

int main(){
	struct rlimit r;

	getrlimit(RLIMIT_NOFILE, &r);
	printf("Max number of open files.\n");
	printf("SOft Limit :%lu \n", r.rlim_cur);
	printf("Hard Limit :%lu \n", r.rlim_max);

	getrlimit(RLIMIT_CPU, &r);
	printf("MAX cpu USAGE in seconds.\n");
	printf("Soft Limit :%lu \n", r.rlim_cur);
	printf("Hard Limit :%lu \n", r.rlim_max);

	getrlimit(RLIMIT_STACK, &r);
	printf("Max stack limit in bytes.\n");
	printf("SOft limit :%lu \n", r.rlim_cur);
	printf("Hard LImit :%lu \n", r.rlim_max);

	getrlimit(RLIMIT_NPROC, &r);
	printf("Max number of process.\n");
	printf("Soft LImit :%lu\n", r.rlim_cur);
	printf("Hard Limit :%lu \n", r.rlim_max);

	printf("There are many resources but I am mentioning few only!!.. using the corresponding  macros we can find there value also \n"); 
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que2$ cc 2.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que2$ ./a.out
Max number of open files.
SOft Limit :1024 
Hard Limit :1048576 
MAX cpu USAGE in seconds.
Soft Limit :18446744073709551615 
Hard Limit :18446744073709551615 
Max stack limit in bytes.
SOft limit :8388608 
Hard LImit :18446744073709551615 
Max number of process.
Soft LImit :30213
Hard Limit :30213 
There are many resources but I am mentioning few only!!.. using the corresponding  macros we can find there value also 
*/