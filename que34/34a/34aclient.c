// Helper for 34a concurrent server using fork problem 


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8081

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    printf("Enter message: ");
    fgets(buffer, sizeof(buffer), stdin);
    write(sock, buffer, strlen(buffer));

    int n = read(sock, buffer, sizeof(buffer)-1);
    buffer[n] = '\0';
    printf("Server replied: %s\n", buffer);

    close(sock);
    return 0;
}

