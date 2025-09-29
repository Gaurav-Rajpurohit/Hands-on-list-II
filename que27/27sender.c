/*
============================================================================
Name : 27helper or sender.c
Author : Gaurav Rajpurohit
Description : 27. Write a program to receive messages from the message queue. 
 a. with 0 as a flag 
 b. with IPC_NOWAIT as a flag 

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
	char mytext[100];

};

int main(){
	key_t key;
	int msgid;

	struct msgbuf message;

	key = ftok(".", 'b');

	msgid = msgget(key, 0666 | IPC_CREAT);

	message.mtype  = 1;
	strcpy(message.mytext, "Hey how are you .... I am sender this side\n");

	msgsnd(msgid, &message, sizeof(message.mytext), 0);

	printf("Message sent from sender side is: %s\n", message.mytext);

	return 0;
}

/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que27$ ./sender
Message sent from sender side is: Hey how are you .... I am sender this side
*/