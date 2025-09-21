/*
============================================================================
Name : 25.c
Author : Gaurav Rajpurohit
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: Sept 17th, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<time.h>

int main(){
	key_t key;
	int msgid;
	struct msqid_ds buf;

	key = ftok(".", 25);

	msgid = msgget(key, 0666 | IPC_CREAT);

	msgctl(msgid, IPC_STAT, &buf);

		printf("Access permission: %o\n", buf.msg_perm.mode);
    	printf("UID: %d\n", buf.msg_perm.uid);
    	printf("GID: %d\n", buf.msg_perm.gid);
    	printf("Time of last msgsnd: %s", buf.msg_stime ? ctime(&buf.msg_stime) : "Not set\n");
    	printf("Time of last msgrcv: %s", buf.msg_rtime ? ctime(&buf.msg_rtime) : "Not set\n");
    	printf("Time of last change: %s", buf.msg_ctime ? ctime(&buf.msg_ctime) : "Not set\n");
   		printf("Current number of bytes in queue: %lu\n", buf.__msg_cbytes);
   		printf("Number of messages in queue: %lu\n", buf.msg_qnum);
   		printf("Max number of bytes allowed: %lu\n", buf.msg_qbytes);
   		printf("PID of last msgsnd: %d\n", buf.msg_lspid);
   		printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que25$ ./a.out
Access permission: 666
UID: 1000
GID: 1000
Time of last msgsnd: Not set
Time of last msgrcv: Not set
Time of last change: Wed Sep 17 19:16:36 2025
Current number of bytes in queue: 0
Number of messages in queue: 0
Max number of bytes allowed: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0
*/