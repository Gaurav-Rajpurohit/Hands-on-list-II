/*
============================================================================
Name : 16.c
Author : Gaurav Rajpurohit
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: Sept 11th, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        exit(1);
    }

    int parent_fds[2], child_fds[2];

    if (pipe(parent_fds) == -1 || pipe(child_fds) == -1) {
        perror("pipe");
        exit(1);
    }

    int child = fork();
    if (child < 0) {
        perror("fork");
        exit(1);
    }

    if (child == 0) {   // Child
        printf("%d : I reached the child\n", getpid());
        fflush(stdout);

        close(child_fds[0]);   // Close read end of child pipe
        close(parent_fds[1]);  // Close write end of parent pipe

        char fromParent[100];
        int n = read(parent_fds[0], fromParent, sizeof(fromParent) - 1);
        if (n <= 0) {
            perror("child read");
            exit(1);
        }
        fromParent[n] = '\0';
        printf("%d: Child reading from parent pipe: %s\n", getpid(), fromParent);

        close(parent_fds[0]);

        // Make sure strcat won’t overflow
        if (strlen(fromParent) + strlen(" (added this)") < sizeof(fromParent)) {
            strcat(fromParent, " (added this)");
        }

        write(child_fds[1], fromParent, strlen(fromParent));
        close(child_fds[1]);
        printf("%d : Child writing to pipe: %s\n", getpid(), fromParent);
        fflush(stdout);
    }
    else {   // Parent
        close(parent_fds[0]);  // Close read end of parent pipe
        close(child_fds[1]);   // Close write end of child pipe

        printf("%d: Parent writing to pipe: '%s'\n", (int)getpid(), argv[1]);
        fflush(stdout);

        write(parent_fds[1], argv[1], strlen(argv[1]));
        close(parent_fds[1]);

        char fromChild[100];
        int n = read(child_fds[0], fromChild, sizeof(fromChild) - 1);
        if (n <= 0) {
            perror("parent read");
            exit(1);
        }
        fromChild[n] = '\0';

        close(child_fds[0]);
        printf("%d: Parent read from pipe: '%s'\n", (int)getpid(), fromChild);
        fflush(stdout);
    }

    return 0;
}


/*OUTPUT

gaurav176@gaurav176-HP-Pavilion-Laptop-14-dv0xxx:~/Desktop/handsonlist2/que16$ ./a.out hello
3931: Parent writing to pipe: 'hello'
3932 : I reached the child
3932: Child reading from parent pipe: hello
3932 : Child writing to pipe: hello (added this)
3931: Parent read from pipe: 'hello (added this)'

*/
