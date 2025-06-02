#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int len, sd;
    char ch1[200], ch2[200];
    struct sockaddr_in sock_address;

    sd = socket(AF_INET, SOCK_DGRAM, 0);
    sock_address.sin_family = AF_INET;
    sock_address.sin_port = htons(8002); 
    sock_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    len = sizeof(sock_address);

    while(1)
    {
        printf("\nEnter the message to Server: ");
        scanf(" %[^\n]", ch1); 
        sendto(sd, ch1, strlen(ch1), 0, (struct sockaddr*)&sock_address, len); 
        recvfrom(sd, ch2, sizeof(ch2), 0, (struct sockaddr*)&sock_address, &len); 
        printf("\nThe message from server: %s\n", ch2);
    }

    close(sd);
    return 0;
}