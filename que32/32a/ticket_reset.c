#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_KEY 5156

int main(){
	int shmid;
	int *ticket;

	shmid = shmget(SHM_KEY, sizeof(int), 0666);

	ticket = (int*) shmat(shmid, NULL, 0);

	*ticket = 0;

	printf("TIcket counter reset to 0\n");

	shmdt(ticket);

	return 0;
}
