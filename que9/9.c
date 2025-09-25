

/*
============================================================================
Name : 9.c
Author : Gaurav Rajpurohit
Description : 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT  signal - Use signal system call. 

Date: Sept 25th, 2025.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(){
	printf("IGNORING SIGINT for 10 seconds...check it with pressing Ctrl + C ... \n");
	signal(SIGINT, SIG_IGN);
	sleep(10);

	printf("Setting to default SIGINT .... check it with pressing Ctrl + C...Now \n");
	signal(SIGINT, SIG_DFL);

	while(1){
		printf("press CTRL+C to terminate ... \n");
		sleep(2);
	}
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que9$ vim 9.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que9$ ./a.out
IGNORING SIGINT for 10 seconds...check it with pressing Ctrl + C ... 
^C ^C^C^C^C^C^CSetting to default SIGINT .... check it with pressing Ctrl + C...Now 
press CTRL+C to terminate ... 
press CTRL+C to terminate ... 
press CTRL+C to terminate ... 
^C
*/