# Lab
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
 
int main(){ int msgid,len;
key_t key;
key = 131;
msgid=msgget(key, IPC_CREAT|0666);
printf(“\nq=%d”,msgid);
}
