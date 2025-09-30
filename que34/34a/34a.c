/*
============================================================================
Name : 34a.c
Author : Gaurav Rajpurohit
Description : 34. Write a program to create a concurrent server. 
 a. use fork 

Date: Sept 30th, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8081
#define BUFFER_SIZE 1024

void handle_client(int client_sock) {
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
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
   

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
     

    listen(server_sock, 5);
    printf("Server listening on port %d\n", PORT);

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
       

      
        if (fork() == 0) {
            close(server_sock); 
            handle_client(client_sock);
            exit(0);
        }

        close(client_sock);
    }

    close(server_sock);
    return 0;
}
/*OUTPUT
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que34/34a$ cc 34aclient.c -o client
gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que34/34a$ ./server
Server listening on port 8081
Received from client: hello

Client disconnected
Received from client: hiii

Client disconnected
Received from client: how are you

Client disconnected
Received from client: youuuu

Client disconnected



gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que34/34a$ ./client
Enter message: youuuu
Server replied: youuuu

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que34/34a$ ./client
Enter message: hiii
Server replied: hiii

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que34/34a$ ./client
Enter message: hello
Server replied: hello

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que34/34a$ ./client
Enter message: how are you
Server replied: how are you
*/