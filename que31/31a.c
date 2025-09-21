/*
============================================================================
Name : 31a.c
Author : Gaurav Rajpurohit
Description : a. Binary Semaphore
Date: Sept st, 2025.
============================================================================
*/


#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdlib.h>

int main(){
	int key, semid;
	
	key = ftok(".",'g');
	semid = semget(key, 1, 0666| IPC_CREAT);

	semctl(semid, 0, SETVAL,1);
	printf("Binary Semaphores created successfully yippeee!!!\n");
	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que31$ ./a.out
Binary Semaphores created successfully yippeee!!!
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que31$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x6706729f 0          gaurav176  666        1         
0x6306729f 1          gaurav176  666        1         

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que31$ ipcs -s -i 0

Semaphore Array semid=0
uid=1000	 gid=1000	 cuid=1000	 cgid=1000
mode=0666, access_perms=0666
nsems = 1
otime = Not set                   
ctime = Sun Sep 21 15:58:21 2025  
semnum     value      ncount     zcount     pid       
0          1          0          0          8201      
*/