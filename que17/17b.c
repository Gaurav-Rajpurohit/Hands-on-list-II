/*
============================================================================
Name : 17b.c
Author : Gaurav Rajpurohit
Description : 17. Write a program to execute ls -l | wc.
b. use dup2
Date: Sept th, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int fd[2];
	pipe(fd);

	if(!fork()){
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execlp("ls","ls","-l",NULL);
	}
	else{
		dup2(fd[0],0);
		close(fd[0]);
		close(fd[1]);
		execlp("wc","wc",NULL);
	}
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que17$ ./a.out
      4      29     183
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que17$ ls -l | wc
      4      29     183
*/