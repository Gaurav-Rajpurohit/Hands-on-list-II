/*
============================================================================
Name : 17c.c
Author : Gaurav Rajpurohit
Description : 17. Write a program to execute ls -l | wc.
c. use fcntl
Date: Sept th, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd[2];
	pipe(fd);

	if(!fork()){
		fcntl(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execlp("ls","ls","-l",NULL);
	}
	else{
		fcntl(fd[0],0);
		close(fd[1]);
		close(fd[0]);
		execlp("wc","wc",NULL);
	}
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que17$ ./a.out
total 28
-rw-rw-r-- 1 gaurav176 gaurav176   807 Sep 17 14:16 17a.c
-rw-rw-r-- 1 gaurav176 gaurav176   816 Sep 17 14:22 17b.c
-rw-rw-r-- 1 gaurav176 gaurav176   326 Sep 17 14:29 17c.c
-rwxrwxr-x 1 gaurav176 gaurav176 16176 Sep 17 14:29 a.out
*/

