
/*
============================================================================
Name : 27b.c
Author : Gaurav Rajpurohit
Description : 27. Write a program to receive messages from the message queue. 
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
	char mtext[100];
};

int main(){
	
	key_t key;
	int msgid;
	struct msgbuf message;

	key = ftok(".", 'b');

	msgid = msgget(key, 0666|IPC_CREAT);

	printf("Trying to receive message (IPC_NOWAIT )\n");

	int r = msgrcv(msgid, &message, sizeof(message.mtext), 1, IPC_NOWAIT);
	
	if(r != -1){	
		printf("Message received from message queue that is already there in it is %s\n", message.mtext);
	}
	else{
		printf("Nothing I got in queue and I have no time to wait ... so BYE BYE... \n");
	}
	return 0;
}

/*OUTPUT

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que27$ ./receiver2
Trying to receive message (IPC_NOWAIT )
Nothing I got in queue and I have no time to wait ... so BYE BYE... 


gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que27$ ./sender
Message sent from sender side is: Hey how are you .... I am sender this side

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que27$ ./receiver2
Trying to receive message (IPC_NOWAIT )
Message received from message queue that is already there in it is Hey how are you .... I am sender this side

*/