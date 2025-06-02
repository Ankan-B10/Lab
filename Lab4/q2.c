#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
    int sockfd, result;
    struct sockaddr_in address;
    char ch1[200], ch2[200];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    socklen_t len = sizeof(address);

    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to server.\n");

    while (1) {
        printf("\nEnter message to server: ");
        scanf(" %[^\n]", ch1);

        write(sockfd, ch1, sizeof(ch1));
        read(sockfd, ch2, sizeof(ch2));

        printf("Message from server: %s\n", ch2);
    }

    close(sockfd);
    return 0;
}
