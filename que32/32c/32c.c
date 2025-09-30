/*
============================================================================
Name : 32c.c
Author : Gaurav Rajpurohit
Description : 32. Write a program to implement semaphore to protect any critical section. 
 c. protect multiple pseudo resources ( may be two) using counting semaphore  
Date: Sept 30th, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/stat.h>

#define SEM_NAME "/write_sem"

int main()
{
    sem_t *sem;

    
    sem = sem_open(SEM_NAME, O_CREAT, 0644, 2);

    printf("Process %d: waiting for a writing...\n", getpid());
    sem_wait(sem);

    printf("Process %d: got a writer! writing...\n", getpid());
    sleep(10);

    printf("Process %d: done writing, releasing writer.\n", getpid());
    sem_post(sem);

    sem_close(sem);
    return 0;
}

/*OUTPUT
Terminal 1
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32c$ cc 32c.c -o program
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32c$ ./program
Process 9972: waiting for a writing...
Process 9972: got a writer! writing...
Process 9972: done writing, releasing writer.

Terminal 2
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32c$ ./program
Process 9974: waiting for a writing...
Process 9974: got a writer! writing...


Terminal 3
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que32/32c$ ./program
Process 9973: waiting for a writing...
Process 9973: got a writer! writing...

*/