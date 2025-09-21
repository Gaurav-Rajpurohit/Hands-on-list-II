/*
============================================================================
Name : 21.c
Author : Gaurav Rajpurohit
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
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
	char *fifo1 = "myfifo1";
	char *fifo2 = "myfifo2";

	mkfifo(fifo1, 0666);
	mkfifo(fifo2, 0666);

	int fd1 = open(fifo1, O_WRONLY);
	int fd2 = open(fifo2, O_RDONLY);

	char msg1[] = "Hello from PersonA\n";
	write(fd1,msg1,strlen(msg1));

	char buf[100];
	int n = read (fd2, buf, sizeof(buf));

	if(n > 0){
		buf[n] ='\0';
		printf("Process A received:%s\n", buf);
	}
	close(fd1);
	close(fd2);
	return 0;
}
/*OUTPUT

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que21$ cc 21personA.c -o Eren

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que21$ cc 21personB.c -o Mikasa
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que21$ ./Mikasa
Message received from person A: Hello from PersonA



gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que21$ ./Eren
Process A received:hello how are you? I am person B

*/