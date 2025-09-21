/*
============================================================================
Name : 14.c
Author : Gaurav Rajpurohit
Description : 14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: Sept 11th, 2025.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	int fd[2];
	pipe(fd);
	char buff[80];

	write(fd[1],"hello\n",6);
	read(fd[0],buff,6);
	
	printf("%s",buff);
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que14$ ./a.out
hello
*/