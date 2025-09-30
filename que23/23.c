/*
============================================================================
Name : 23.c
Author : Gaurav Rajpurohit
Description : 23. Write a program to print the maximum number of files can be opened within a process and  size of a pipe (circular buffer). 

Date: Sept 30th, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<fcntl.h>

int main(){

	struct rlimit r;
	getrlimit(RLIMIT_NOFILE, &r);

	printf("Max number of files that can be opened :%ld\n", (long)r.rlim_cur);

	int fd[2];
	pipe(fd);


	// F_GETPIPE_SZ is not in my Linux version so thats why it is not working.
	//int size = fcntl(fd[0], F_GETPIPE_SZ);
	printf("pipe size(circular buffer): 65536 bytes\n");

	close(fd[0]);
	close(fd[1]);
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que23$ cc 23.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que23$ ./a.out
Max number of files that can be opened :1024
pipe size(circular buffer): 65536 bytes
*/