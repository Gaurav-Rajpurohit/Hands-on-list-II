/*
============================================================================
Name : 15.c
Author : Gaurav Rajpurohit
Description : Write a simple program to send some data from parent to the child process.
Date: Sept 11th, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	int fd[2];
	pipe(fd);

	char buff[80];

	if(!fork()){
		close(fd[1]);
		read(fd[0],buff,6);
		printf("%s",buff);

	}
	else{
		close(fd[0]);
		write(fd[1],"hello\n",6);
		wait(0);	
	}
}

/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que15$ ./a.out
hello
*/
