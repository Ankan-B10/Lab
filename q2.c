// To sending msg to the msg queue
#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/img.n
#include <stdio.h>
#include <stdlib.h>

struct message {
    long mtype;
    Char mtext [150];
}

int main(){

    int msgid, len;
    struct message msg;
    Key_t key;
    Key = 131;

    msgid = msgget (key, IPC_CREAT|0666);
    printf ("\n q= %d", msgid);
    printf ("Enter the message: ");
    Scanf ("%[^\n]s", msg.mtext);
    msg.mtype = 1,
    len = strlen(msg.mtext);
    if (msgnd (msgid, &msg, len, 0) == -1)
    {
    printf ("error \n");
    exit(1);
    }
return 0;
}

//gcc -o b q2.c
// ./b
// ipcs -q
// ./b