/*
============================================================================
Name : 32d.c
Author : Gaurav Rajpurohit
Description : 32. Write a program to implement semaphore to protect any critical section.  
d. remove the created semaphore 

Date: Sept st, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#define SEM_KEY 5150

int main() {
    int semid;

   
    semid = semget(SEM_KEY, 1, 0666 |IPC_CREAT);
    
    sleep(50);

   
     (semctl(semid, 0, IPC_RMID) == -1) 
       
    

    printf("Semaphore with key %d removed successfully.\n", SEM_KEY);
    return 0;
}


/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32d$ ./a.out

Semaphore with key 5150 removed successfully.

Before completing sleep cycle
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32d$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x0000141e 10         gaurav176  666        1        

After completing the sleep cycle
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32d$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     



*/