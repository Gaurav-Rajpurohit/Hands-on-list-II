/*
============================================================================
Name : 27a.c
Author : Gaurav Rajpurohit
Description :  27. Write a program to receive messages from the message queue. 
 a. with 0 as a flag 
Date: Sept 29th, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct msgbuf{
	long mtype;
	char msgtext[100];

};

int main(){
	key_t key;
	int msgid;
	struct msgbuf message;

	key = ftok(".", 'b');

	msgid = msgget(key, 0666 | IPC_CREAT);

	printf("Waiting for message bhaiiii ... \n");


	msgrcv(msgid, &message, sizeof(message.msgtext),1, 0);
	
	printf("Message I received (No flags) is :%s \n",message.msgtext);

	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que27$ ./sender
Message sent from sender side is: Hey how are you .... I am sender this side

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que27$ ./receiver1
Waiting for message bhaiiii ... 

AFter running the sender code on different terminal
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que27$ ./receiver1
Waiting for message bhaiiii ... 
Message I received (No flags) is :Hey how are you .... I am sender this side
 

*/