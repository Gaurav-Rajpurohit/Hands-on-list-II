/*
============================================================================
Name : 32a.c
Author : Gaurav Rajpurohit
Description : 32. Write a program to implement semaphore to protect any critical section.  
a. rewrite the ticket number creation program using semaphore 

Date: Sept 30th, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<sys/shm.h>


#define SHM_KEY  5156
#define SEM_KEY 1374

struct sembuf p = {0,-1, 0};
struct sembuf v = {0, 1, 0};

int main(){

	int shmid, semid;
	int *ticket =0 ;


	shmid = shmget(SHM_KEY, sizeof(int), IPC_CREAT |0666);
	ticket = (int*) shmat(shmid, NULL,0);

	semid = semget(semid, 1, IPC_CREAT|0666);
	semctl(semid, 0, SETVAL, 1);


	for(int i = 0; i < 5;i++){
		semop(semid, &p, 1);

		(*ticket)++;
		printf("Ticket number :%d\n", *ticket);
		fflush(stdout);	
		semop(semid, &v, 1);
		sleep(1);
	}

	shmdt(ticket);

	return 0;
}

/*OUTPUT
Terminal 1
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32a$ ./ticket
Ticket number :1
Ticket number :3
Ticket number :5
Ticket number :7
Ticket number :9

Terminal 2
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32a$ ./ticket
Ticket number :2
Ticket number :4
Ticket number :6
Ticket number :8
Ticket number :10

*/