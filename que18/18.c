/*
============================================================================
Name : 18.c
Author : Gaurav Rajpurohit
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: Sept 17th, 2025.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int fd1[2],fd2[2];
	pipe(fd1);
	pipe(fd2);

	if(!fork()){
		dup2(fd1[1],1);
		close(fd1[0]);close(fd1[1]);
		close(fd2[0]);close(fd2[1]);

		execlp("ls","ls","-l", NULL);
	}
	if(!fork()){
		dup2(fd1[0],0);
		dup2(fd2[1],1);
		close(fd1[0]);
		close(fd1[1]);
		close(fd2[0]);
		close(fd2[1]);
		execlp("grep","grep","^d",NULL);
	}
	dup2(fd2[0],0);
	 close(fd1[0]);
         close(fd1[1]);
         close(fd2[0]);
         close(fd2[1]);
	execlp("wc","wc",NULL);
return 0;
}

/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que18$ ./a.out
      1       9      58
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que18$ ls -l | grep ^d | wc
      1       9      58

*/