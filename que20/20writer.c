/*
============================================================================
Name : 20.c
Author : Gaurav Rajpurohit
Description :Write two programs so that both can communicate by FIFO -Use one way communication. 
Date: Sept 17th, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	char *fifo = "myfifo";
	mkfifo(fifo, 0666);

	int fd = open(fifo, O_WRONLY);

	char msg[]= "Hello!! I am EREN YAEGAR\n";

	write(fd,msg,strlen(msg));
	printf("writer sent:%s\n",msg);
	close(fd);
	return 0;
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que20$ ./writer
writer sent:Hello!! I am EREN YAEGAR
*/