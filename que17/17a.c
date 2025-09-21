/*
============================================================================
Name : 17a.c
Author : Gaurav Rajpurohit
Description : 17. Write a program to execute ls -l | wc.
a. use dup
Date: Sept 17th, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int fd[2];
	pipe(fd);

	if(!fork()){
		close(fd[0]);
		close(1);
		dup(fd[1]);
		execlp("ls", "ls", "-l", NULL);
	}
	else{
		close(fd[1]);
		close(0);
		dup(fd[0]);
		execlp("wc","wc",NULL);
	}
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que17$ ./a.out
      3      20     125
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que17$ ls -l | wc
      3      20     125
*/

