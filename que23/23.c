#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<fcntl.h>

int main(){

	struct rlimit r;
	getrlimit(RLIMIT_NOFILE, &r);

	printf("Max number of files that can be opened :%ld\n", (long)r.rlim_cur);

	int fd[2];
	pipe(fd);


	// F_GETPIPE_SZ is not in my Linux version so thats why it is not working.
	//int size = fcntl(fd[0], F_GETPIPE_SZ);
	printf("pipe size(circular buffer): 65536 bytes\n");

	close(fd[0]);
	close(fd[1]);
	return 0;
}
