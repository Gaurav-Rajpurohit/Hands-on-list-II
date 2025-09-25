/*
============================================================================
Name : 12.c
Author : Gaurav Rajpurohit
Description : 12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to  the parent process from the child process. 

Date: Sept 25th, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>


int main(){
	
	if(!fork()){
		printf("Child process id : %d and parent process id : %d\n", getpid(), getppid());
		sleep(1);

		printf("child is killing parent using kill system call\n");
		kill(getppid(), SIGKILL);

		sleep(2);
		

		printf("Child process id : %d and parent process id :%d \n", getpid(), getppid());
	}

	else{
		printf("Parent process id is %d\n", getpid());

		sleep(5);
	}
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que12$ ./a.out
Parent process id is 9307
Child process id : 9308 and parent process id : 9307
child is killing parent using kill system call
Killed
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que12$ Child process id : 9308 and parent process id :2191 
*/