/*
============================================================================
Name : 30c.c
Author : Gaurav Rajpurohit
Description : c. detach the shared memory
Date: Sept 21st, 2025.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>


int main(){
	int key;  
	key = ftok(".",'b');
	char *data;

	int shmid = shmget(key, 1024, 0666|IPC_CREAT);
	data = shmat(shmid, 0, 0);
	printf("Attached data :%s\n", data);
	printf("shared Memory id :%d\n", shmid);
	shmdt(data);
	return 0;}

	/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ ./a.out
Attached data :Hi Gaurav whats your name
shared Memory id :14
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 8          gaurav176  606        11657952   2          dest         
0x00000000 9          gaurav176  606        11657952   2          dest         
0x00000000 13         gaurav176  600        524288     2          dest         
0x62064502 14         gaurav176  744        1024       0                       

*/