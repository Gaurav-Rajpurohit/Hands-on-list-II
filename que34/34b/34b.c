/*
============================================================================
Name : 34b.c
Author : Gaurav Rajpurohit
Description : 34. Write a program to create a concurrent server. 
b. using thread

Date: Sept 30th, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8082
#define BUFFER_SIZE 1024

void* handle_client(void* arg) {
    int client_sock = *(int*)arg;
    free(arg);

    char buffer[BUFFER_SIZE];
    int n;

    n = read(client_sock, buffer, sizeof(buffer) - 1);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Received from client: %s\n", buffer);
        write(client_sock, buffer, strlen(buffer)); 
    }

    close(client_sock);
    printf("Client disconnected\n");
    return NULL;
}

int main() {
    int server_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(server_sock, 5);
    printf("Server listening on port %d\n", PORT);

    while (1) {
        int* client_sock = malloc(sizeof(int));
        *client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
      

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, client_sock);
        pthread_detach(tid); 
    }

    close(server_sock);
    return 0;
}


/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que34/34b$ ./server
Server listening on port 8082
Received from client: hii eren 

Client disconnected
Received from client: hello mikasa

Client disconnected
Received from client: hello erwin

Client disconnected
Received from client: hello armin

Client disconnected



gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que34/34b$ ./client
Enter message: hello mikasa
Server replied: hello mikasa

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que34/34b$ ./client
Enter message: hello armin
Server replied: hello armin

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que34/34b$ ./client
Enter message: hello erwin
Server replied: hello erwin

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que34/34b$ ./client
Enter message: hii eren 
Server replied: hii eren 
*/