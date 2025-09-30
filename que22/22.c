/*
============================================================================
Name : 22.c
Author : Gaurav Rajpurohit
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: Sept 17th, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/time.h>
#include<sys/select.h>

int main(){
	char *fifo = "myfifo";
	mkfifo(fifo,0666);

	int fd = open(fifo, O_RDONLY| O_NONBLOCK);
	fd_set readfds;
	struct timeval tv;

	FD_ZERO(&readfds);
	FD_SET(fd, &readfds);

	tv.tv_sec = 10;
	tv.tv_usec = 0;

	printf("Waiting for data on FIFO(for 10seconds)... \n");

	int ret = select(fd+1, &readfds, NULL, NULL, &tv);
	
	if(ret == 0){
		printf("TimeOut: No data written in 10 seconds\n");
	}
	else{
		if(FD_ISSET(fd, &readfds)){
			char buf[100];
			int n = read(fd, buf, sizeof(buf));
			if(n > 0){
				buf[n] = '\0';
				printf("Received :%s\n", buf);
			}
			else{
				printf("NOthing to read\n");
			}
		}
	}
	return 0;
}

/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que22$ ./fifoselect
Waiting for data on FIFO(for 10seconds)... 
Received :hello how are you

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que22$ echo "hello how are you" > myfifo


gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que22$ ./fifoselect
Waiting for data on FIFO(for 10seconds)... 
TimeOut: No data written in 10 seconds
*/
