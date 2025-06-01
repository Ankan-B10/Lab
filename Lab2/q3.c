//To receive message from the message queue
#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Struct message {
    long mtype;
    char mtext[15];
};

int main(){
    int msgid, len=20
    key_t key;
    Struct message buff;
    key=131;

    msgid = msgget (key, IPC_CREAT|0666);

    printf("\nq= %d", msgid);

    if (msgrcv (msgid, &buff, len, 0, 0) == -1)
    {
    perror ("msg failed \n");
    exit(1);
    }
    printf("\n msg received %s", buff. mtext);
return 0;
}