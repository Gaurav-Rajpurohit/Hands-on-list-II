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
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	char *fifo = "myfifo";
	mkfifo(fifo,0666);

	int fd = open(fifo, O_RDONLY);

	char buff[100];

	int n = read(fd, buff, sizeof(buff));

	if(n > 0){
		buff[n] = '\0';
		printf("Reader got:%s\n",buff);
	}
	close(fd);
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que20$ ./reader
Reader got:Hello!! I am EREN YAEGAR
*/