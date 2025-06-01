//TCP client that connects to server
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main (){

int sockfd, len, result;

struct sockaddr_in address;

char name[100], ser[100];
sockfd = socket (AF_INET, SOCK_STREAM,0);

address.sin_family = AF_INET;

address.sin_port = 8080;

address.sin_addr.s_addr = inet_addr("127.0.0.1");

len = sizeof(address);

result = connect (sockfd, (struct sockaddr*)&address, len);
if (result == -1){

perror ("Unable to connect");
exit (1);
}
printf("Enter the message: ");
scanf ("%[^\n]s", name);

write(sockfd, name, sizeof(name));
read (sockfd, ser, sizeof(ser));
printf ("\n Reading from server: %s \n", ser);
close (sockfd);
return (0);
}