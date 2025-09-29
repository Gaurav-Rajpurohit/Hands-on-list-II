/*
============================================================================
Name : 13b.c
Author : Gaurav Rajpurohit
Description : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program  will send the signal (using kill system call). Find out whether the first program is able to catch  the signal or not. 

Date: Sept 29th, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>


int main(int argc, char *argv[]){

	pid_t pid = atoi(argv[1]);

	printf("Sending stop signal to process with PID %d\n", pid);

	kill(pid, SIGSTOP);

	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que13$ ./program2 20057
Sending stop signal to process with PID 20057
*/