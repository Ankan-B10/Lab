//creates TCP server
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

int serv_sockfd, cli_sockfd;

int serv_len, cli_len;

struct sockaddr_in serv_address, cli_address;

char a[100], b[100];

serv_sockfd = socket (AF_INET, SOCK-STREM,0);

serv_address.sin_family = AF_INET;

serv_address.sin_port = 8080;

serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");

serv_len = sizeof(serv_address);

bind (serv_sockfd, (struct sockaddr*) &serv_address, serv_len);

listen (serv_sockfd, 5);

while (1) {

printf(" server is waiting...");

cli_len = sizeof(cli_address);

cli_socked = accept(serv_sockfd, (struct sockaddr*) &cli_address, &cli_len);
read (cli_sockfd, a, sizeof(a));

printf("Reading message from client :%s", a);

write(cli_sockfd, b, sizef(b));
printf ("Enter a message for client: ");
scanf("% [^\n]s", b);

close (cli_sockbd);

}