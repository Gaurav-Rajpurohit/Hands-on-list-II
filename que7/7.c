#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void threadfunc(void *varg){

	printf("Threads is doing its work and its id is %lu\n",pthread_self());

	
}

int main(){

	pthread_t t1;

	pthread_create(&t1, NULL,(void*) threadfunc, NULL);

	pthread_join(t1, NULL);

	return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que7$ ./a.out
Threads is doing its work and its id is 125961959896768
*/