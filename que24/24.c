/*
============================================================================
Name : 24.c
Author : Gaurav Rajpurohit
Description : Write a program to create a message queue and print the key and message queue id.
Date: Sept 17th, 2025.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main(){
	key_t key;
	int msgid;

	key = ftok(".",12);

	msgid = msgget(key, 0666 | IPC_CREAT);

	printf("Message Queue Created successfully hoorahhh\n");
	printf("key :%d \n",key);
	printf("Message Queue Id : %d\n", msgid);
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que24$ ./a.out
Message Queue Created successfully hoorahhh
key :201742416 
Message Queue Id : 1
*/