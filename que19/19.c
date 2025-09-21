/*
============================================================================
Name : 19.c
Author : Gaurav Rajpurohit
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: Sept 17th, 2025.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	system("mknod fifo_a p");
	printf("FIFO created using mknod command (fifo_a)\n");

	system("mkfifo fifo_b");
	printf("FIFO created using mkfifo command (fifo_b)\n");

	system("strace -c mkfifo fifo_c");
	printf("c.mkfifo internally calls mknod\n");

	mknod("fifo_d",S_IFIFO|0666,0);
	mkfifo("fifo_e",0666);

	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que19$ ls -l
total 20
-rw-rw-r-- 1 gaurav176 gaurav176   434 Sep 17 14:55 19.c
-rwxrwxr-x 1 gaurav176 gaurav176 16088 Sep 17 14:55 a.out
prw-rw-r-- 1 gaurav176 gaurav176     0 Sep 17 14:55 fifo_a
prw-rw-r-- 1 gaurav176 gaurav176     0 Sep 17 14:55 fifo_b
prw-rw-r-- 1 gaurav176 gaurav176     0 Sep 17 14:55 fifo_c
prw-rw-r-- 1 gaurav176 gaurav176     0 Sep 17 14:55 fifo_d
prw-rw-r-- 1 gaurav176 gaurav176     0 Sep 17 14:55 fifo_e
*/