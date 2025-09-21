#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>

int main(void){
	int key, shmid;
	char *data;

	key = ftok(".",'b');
	shmid = shmget(key,1024,IPC_CREAT|0744);
	data = shmat(shmid, 0, 0);
	printf("Enter the text:");
	scanf("%[^\n]",data);
}
