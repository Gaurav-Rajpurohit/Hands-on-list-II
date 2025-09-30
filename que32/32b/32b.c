/*
============================================================================
Name : 32b.c
Author : Gaurav Rajpurohit
Description : 32. Write a program to implement semaphore to protect any critical section.  
 b. protect shared memory from concurrent write access 

Date: Sept 30th, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 5157
#define SEM_KEY 1374


union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    int shmid, semid;
    char *shm_ptr;

   
    shmid = shmget(SHM_KEY, 1024, 0666 | IPC_CREAT);
  
    shm_ptr = (char *) shmat(shmid, NULL, 0);
    
    semid = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
   

   
    union semun u;
    u.val = 1;
    semctl(semid, 0, SETVAL, u);

   
    struct sembuf p = {0, -1, 0};
    struct sembuf v = {0, 1, 0};  

    
    semop(semid, &p, 1);

    printf("Process %d is writing into shared memory...\n", getpid());
    snprintf(shm_ptr, 1024, "Hello from process %d..\n", getpid());
    sleep(3); 

    printf("Process %d finished writing.\n", getpid());

    
    semop(semid, &v, 1);

    shmdt(shm_ptr);

    return 0;
}

/*OUTPUT
Terminal 1
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32b$ ./writer
Process 6773 is writing into shared memory...
Process 6773 finished writing.

Terminal1
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32b$ ./reader
Reader (PID 6775) read: Hello from process 6774..

Terminal 2
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32b$ vim reader.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32b$ ./writer
Process 6774 is writing into shared memory...
Process 6774 finished writing.

*/