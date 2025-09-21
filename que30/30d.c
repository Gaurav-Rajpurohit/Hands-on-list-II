/*
============================================================================
Name : 30d.c
Author : Gaurav Rajpurohit
Description : d. Remove the shared memory
Date: Sept 21st, 2025.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>


int main(){
	int key, shmid;
	key = ftok(".", 'b');

	shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}
/*
OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ ./a.out
Enter the text:hii
The shared memory id is 15
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 8          gaurav176  606        11657952   2          dest         
0x00000000 9          gaurav176  606        11657952   2          dest         
0x00000000 13         gaurav176  600        524288     2          dest         
0x62064502 15         gaurav176  744        1024       0                       

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ cc 30d.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ ./a.out
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 8          gaurav176  606        11657952   2          dest         
0x00000000 9          gaurav176  606        11657952   2          dest         
0x00000000 13         gaurav176  600        524288     2          dest         

*/