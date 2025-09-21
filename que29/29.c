/*
============================================================================
Name : 29.c
Author : Gaurav Rajpurohit
Description : Write a program to remove the message queue. 
Date: Sept th, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main(){
	key_t key;
	int msgid;


	key = ftok(".", 23);

	msgid = msgget(key, 0666 | IPC_CREAT);
	printf("message queue id :%d\n", msgid);
	getchar();
	

	msgctl(msgid, IPC_RMID, NULL);

	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que29$ ./a.out
message queue id :5


gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que22$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          gaurav176  666        0            0           
0x0c065850 1          gaurav176  666        0            0           
0x19065a0a 2          gaurav176  666        0            0           
0x1a0659eb 3          gaurav176  666        200          2           
0x17065a71 5          gaurav176  666        0            0      

after getchar()

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que22$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          gaurav176  666        0            0           
0x0c065850 1          gaurav176  666        0            0           
0x19065a0a 2          gaurav176  666        0            0           
0x1a0659eb 3          gaurav176  666        200          2           



*/