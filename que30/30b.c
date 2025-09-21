
/*
============================================================================
Name : 30b.c
Author : Gaurav Rajpurohit
Description : b. attach with O_RDONLY and check whether you are able to overwrite.
Date: Sept 21st, 2025.
============================================================================
*/



#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>


int main(){
	int key, shmid;
	char *data;

	key = ftok(".", 'b');
	shmid = shmget(key, 1024,0);
	data = shmat(shmid, 0,SHM_RDONLY);

	printf("Text from shared Memory : %s\n", data);
	strcpy(data,"hiii");

	shmdt(data);
	return 0;
}

/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ cc 30.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ ./a.out
Enter the text:Hi Gaurav whats your name
The shared memory id is 14
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ cc 30b.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ ./a.out
Text from shared Memory : Hi Gaurav whats your name
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que30$ ./a.out
Text from shared Memory : Hi Gaurav whats your name
Segmentation fault (core dumped)

*/
