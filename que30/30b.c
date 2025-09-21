#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>

int main(){
	int key, shmid;
	char *data;

	key = ftok(".", 'b');
	shmid = shmget(key, 1024,0);
	data = shmat(shmid, 0,0);
	printf("Text from shared Memory : %s\n", data);
}
