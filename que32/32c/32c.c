#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

#define SEM_KEY 1000

// union required by semctl
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    int semid;

    // Create semaphore set with 1 semaphore
    semid = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Check current value of semaphore
    int current_val = semctl(semid, 0, GETVAL);
    if (current_val == -1) {
        perror("semctl GETVAL");
        exit(1);
    }

    // Only initialize if it is the first time (value = 0 means uninitialized)
    if (current_val == 0) {
        union semun u;
        u.val = 2;  // allow 2 processes at a time
        if (semctl(semid, 0, SETVAL, u) == -1) {
            perror("semctl SETVAL");
            exit(1);
        }
        printf("Semaphore initialized with value 2\n");
    }

    struct sembuf p = {0, -1, 0}; // wait (P operation)
    struct sembuf v = {0, 1, 0};  // signal (V operation)

    printf("Process %d is trying to acquire a resource...\n", getpid());
    if (semop(semid, &p, 1) == -1) {
        perror("semop P");
        exit(1);
    }

    printf("Process %d has acquired the resource!\n", getpid());
    sleep(10);

    if (semop(semid, &v, 1) == -1) {
        perror("semop V");
        exit(1);
    }
    printf("Process %d released the resource.\n", getpid());

    return 0;
}
