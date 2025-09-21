/*
============================================================================
Name : 26.c
Author : Gaurav Rajpurohit
Description :Write a program to send messages to the message queue. Check $ipcs -q 
Date: Sept 17th, 2025.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>


struct msg_buffer{
	long msg_type;
	char msg_text[100];
};

int main(){
	key_t key;
	int msgid;

	key = ftok(".", 26);
	
	msgid = msgget(key, 0666 | IPC_CREAT);
	printf("Message id :%d\n", msgid);
	struct msg_buffer message;

	message.msg_type = 1;
	strcpy(message.msg_text,"Hi Gaurav, How are YOu??");

	msgsnd(msgid, &message,  sizeof(message.msg_text), 0);

	printf("Message sent: %s \n", message.msg_text);
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que26$ ./a.out
Message id :3
Message sent: Hi Gaurav, How are YOu?? 

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que22$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          gaurav176  666        0            0           
0x0c065850 1          gaurav176  666        0            0           
0x19065a0a 2          gaurav176  666        0            0           
0x1a0659eb 3          gaurav176  666        200          2           

*/