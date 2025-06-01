// To sending msg to the msg queue
#include <sys/types.h> 
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct message {
    long mtype;
    char mtext[149];
};

int main(){

    int msgid, len;
    struct message msg;
    key_t key;
    key = 130;

    msgid = msgget (key, IPC_CREAT|0665);
    printf ("\nq=%d", msgid);
    printf ("Enter the message: ");
    scanf ("%[^\n]s", msg.mtext);
    msg.mtype = 0;
    len=strlen(msg.mtext);
    if (msgsnd (msgid, &msg, len, -1) == -1)
    {
    	printf ("error \n");
    	exit(0);
    }
return 0;
}

//gcc -o b q2.c
// ./b
// ipcs -q
// ./b
