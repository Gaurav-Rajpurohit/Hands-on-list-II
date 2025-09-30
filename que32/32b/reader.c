#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 5157

int main() {
    int shmid;
    char *shm_ptr;

   
    shmid = shmget(SHM_KEY, 1024, 0666);
   

    shm_ptr = (char *) shmat(shmid, NULL, 0);
    

    printf("Reader (PID %d) read: %s\n", getpid(), shm_ptr);

    shmdt(shm_ptr);

    return 0;
}
