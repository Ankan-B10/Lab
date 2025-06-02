#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>

int main()
{
    int s_sd, serv_len;
    char sour[200], dest[200];
    struct sockaddr_in serv;

    s_sd = socket(AF_INET, SOCK_DGRAM, 0);
    serv_len = sizeof(serv);
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8002); 
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(s_sd, (struct sockaddr*)&serv, serv_len);
    printf("\nThe SERVER is WAITING .........\n");

    while(1)
    {
        recvfrom(s_sd, sour, sizeof(sour), 0, (struct sockaddr*)&serv, &serv_len);
        printf("\nThe message from client is : %s", sour);
        printf("\nEnter the message for Client: ");
        scanf(" %[^\n]", dest); 
        sendto(s_sd, dest, strlen(dest), 0, (struct sockaddr*)&serv, serv_len);
    }

    close(s_sd);
    return 0;
}