#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int sockfd, len;
    struct sockaddr_in address;
    int number, reversed;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(9055);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    len = sizeof(address);

    printf("Enter the number: ");
    scanf("%d", &number);

    sendto(sockfd, &number, sizeof(number), 0, (struct sockaddr *)&address, len);
    recvfrom(sockfd, &reversed, sizeof(reversed), 0, (struct sockaddr *)&address, &len);
    printf("Message from server (reversed number): %d\n", reversed);

    close(sockfd);
    return 0;
}
