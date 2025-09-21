/*
============================================================================
Name : 6.c
Author : Gaurav Rajpurohit
Description : 6. Write a simple program to create three threads. 

Date: Sept 21st, 2025.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *thread1(void *varg){
	printf("I am in thread 1\n");
	return NULL;
}

void *thread2 (void *varg){
	int n = *((int*) varg);
	int * result = malloc(sizeof(int));
	*result = n*n;
	printf("Thread 2 is calculating square of number %d *%d = %d\n",n,n, *result);
	return result;
}

void *thread3(void *varg){
	printf("COUGH COUGH Thread 3 is here\n");
	return NULL;
}

int main(){
	pthread_t tid1, tid2, tid3;
	int val = 5;
	void * ret;
	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, &val);
	pthread_create(&tid3, NULL, thread3, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, &ret);
	pthread_join(tid3, NULL);
	
	int res = *((int *) ret);
	printf("Thread 2 is returing the square of value :%d is equal to %d\n",val, res);
	
	return 0;
}

/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que6$ cc 6.c
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que6$ ./a.out
COUGH COUGH Thread 3 is here
Thread 2 is calculating square of number 5 *5 = 25
I am in thread 1
Thread 2 is returing the square of value :5 is equal to 25
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que6$ ./a.out
COUGH COUGH Thread 3 is here
I am in thread 1
Thread 2 is calculating square of number 5 *5 = 25
Thread 2 is returing the square of value :5 is equal to 25
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que6$ ./a.out
I am in thread 1
COUGH COUGH Thread 3 is here
Thread 2 is calculating square of number 5 *5 = 25
Thread 2 is returing the square of value :5 is equal to 25

*/
