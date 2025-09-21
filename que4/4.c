/*
============================================================================
Name : 4.c
Author : Gaurav Rajpurohit
Description : 4. Write a program to measure how much time is taken to execute 100 getppid ( )  system call. Use time stamp counter.  

Date: Sept 21st, 2025.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc(){
	unsigned long long dst;
	__asm__ __volatile__ ("rdtsc" : "=A"(dst));
	return dst;
}

int main(){
	unsigned long long start, end;
	int pid;
	int i ;
	start = rdtsc();
	
	for(i = 0;i<100;i++){
		pid = getppid();
	}

	end = rdtsc();

	printf("Parent pid last one : %d\n", pid);
	printf("CPU cycles for 100 getppid() calls :%llu\n", end - start);
	printf("Average Cpu cycles :%llu \n", (end - start)/100);

	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que4$ cc 4.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que4$ ./a.out
Parent pid last one : 3747
CPU cycles for 100 getppid() calls :130849
Average Cpu cycles :1308 

*/