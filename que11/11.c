/*
============================================================================
Name : 11.c
Author : Gaurav Rajpurohit
Description : 11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -  use sigaction system call. 
Date: Sept 25th, 2025.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>


int main(){
	struct sigaction s_ign, s_dfl;

	s_ign.sa_handler = SIG_IGN;
	sigemptyset(&s_ign.sa_mask);
	s_ign.sa_flags = 0;

	sigaction(SIGINT, &s_ign, NULL);

	printf("Interrupt signal is off for 10 seconds... PRESS Ctrl + C to check it ... \n");
	sleep(10);

	s_dfl.sa_handler = SIG_DFL;
	sigemptyset(&s_dfl.sa_mask);
	s_ign.sa_flags = 0;

	sigaction(SIGINT, &s_dfl, NULL);

	printf("Interrupt is back to work... check it with pressing CTRL +C ... \n");


	while(1){
		printf("Press CTRL + C to terminate... \n");
		sleep(2);
	}
	return 0;
}


/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que11$ cc 11.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que11$ ./a.out
Interrupt signal is off for 10 seconds... PRESS Ctrl + C to check it ... 
^C^C^C^C^C^C^C^CInterrupt is back to work... check it with pressing CTRL +C ... 
Press CTRL + C to terminate... 
Press CTRL + C to terminate... 
^C
*/
