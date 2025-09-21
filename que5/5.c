/*
============================================================================
Name : 5.c
Author : Gaurav Rajpurohit
Description : 5. Write a program to print the system limitation of  
 a. maximum length of the arguments to the exec family of functions.  
 b. maximum number of simultaneous process per user id.  
 c. number of clock ticks (jiffy) per second.  
 d. maximum number of open files 
 e. size of a page 
 f. total number of pages in the physical memory 
 g. number of currently available pages in the physical memory.  

Date: Sept 21st, 2025.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<stdlib.h>
#include<sys/sysinfo.h>

int main(){
	struct rlimit r;

	printf("a. Maximum Length of arguments to exec :%ld\n", sysconf(_SC_ARG_MAX));

	getrlimit(RLIMIT_NPROC, &r);
	printf("b.No of simultaneous process--> soft limit : %ld and hard limit: %ld\n",r.rlim_cur, r.rlim_max);

	printf("c. No of clock ticks per seconds :%ld \n", sysconf(_SC_CLK_TCK));

	getrlimit(RLIMIT_NOFILE, &r);
	printf("d. No of open files --> Soft Limit :%ld and hard limit :%ld\n",r.rlim_cur, r.rlim_max);

	printf("e.Page size:%ld\n", sysconf(_SC_PAGESIZE));

	printf("f.Total number of physical memory pages :%ld\n", sysconf(_SC_PHYS_PAGES));


	printf("g. Number of available physical memory pages:%ld\n", sysconf(_SC_AVPHYS_PAGES));

	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que5$ vim 5.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que5$ cc 5.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que5$ ./a.out
a. Maximum Length of arguments to exec :2097152
b.No of simultaneous process--> soft limit : 30213 and hard limit: 30213
c. No of clock ticks per seconds :100 
d. No of open files --> Soft Limit :1024 and hard limit :1048576
e.Page size:4096
f.Total number of physical memory pages :1972952
g. Number of available physical memory pages:168395

*/