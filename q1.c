//creating Message queue using MSGGET sysyem call
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int msgid,len;
    key_t key;
    key = 131;
    msgid = msgget(key, IPC_CREAT|0666);
    printf("\nq=%d",msgid);
} 	

//gcc -o a q1.cpp
// ./a
// ipcs -q
