#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int serv_sockfd;
    socklen_t serv_len;
    struct sockaddr_in serv_address, client_address;
    int a, rev = 0, r, n;

    serv_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (serv_sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(9055);
    serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_len = sizeof(serv_address);

    if (bind(serv_sockfd, (struct sockaddr *) &serv_address, sizeof(serv_address)) < 0) {
        perror("Bind failed");
        close(serv_sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server is working...\n");

    socklen_t client_len = sizeof(client_address);
    if (recvfrom(serv_sockfd, &a, sizeof(a), 0,
                 (struct sockaddr *) &client_address, &client_len) < 0) {
        perror("recvfrom failed");
        close(serv_sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Message from client: %d\n", a);

    n = a;
    rev = 0;
    while (n > 0) {
        r = n % 10;
        rev = rev * 10 + r;
        n = n / 10;
    }

    if (sendto(serv_sockfd, &rev, sizeof(rev), 0,
               (struct sockaddr *) &client_address, client_len) < 0) {
        perror("sendto failed");
        close(serv_sockfd);
        exit(EXIT_FAILURE);
    }

    close(serv_sockfd);
    return 0;
}
