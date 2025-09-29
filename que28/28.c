/*
============================================================================
Name : 28.c
Author : Gaurav Rajpurohit
Description : 28. Write a program to change the existing message queue permission. (use msqid_dsstructure) 

Date: Sept 29th, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main(){
	key_t key;
	int msgid;
	struct msqid_ds buf;

	key = ftok(".",'b');

	msgid = msgget(key, 0666 | IPC_CREAT);

	msgctl(msgid, IPC_STAT, &buf);

	printf("Old permission :%o \n", buf.msg_perm.mode & 0777);

	buf.msg_perm.mode = 0744;

	msgctl(msgid, IPC_SET, &buf);

	printf("New permission :%o \n", buf.msg_perm.mode & 0777);

	return 0;
}

/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que28$ cc 28.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que28$ ./a.out
Old permission :666 
New permission :744 
*/