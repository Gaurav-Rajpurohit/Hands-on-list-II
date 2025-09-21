#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>


struct msg_buffer{
	long msg_type;
	char msg_text[200];
}

int main(){
	key_t key;
	int msgid;
	struct msg_buffer message;

	key = ftok
