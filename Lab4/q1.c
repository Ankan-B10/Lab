#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int s_sd, c_sd;
    struct sockaddr_in serv, cli;
    char recv_msg[200], send_msg[200];

    s_sd = socket(AF_INET, SOCK_STREAM, 0);
    if (s_sd < 0) {
        perror("Socket creation failed");
        exit(1);
    }
z
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8080);
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");
    socklen_t serv_len = sizeof(serv);

    if (bind(s_sd, (struct sockaddr *)&serv, serv_len) < 0) {
        perror("Bind failed");
        exit(1);
    }

    if (listen(s_sd, 5) < 0) {
        perror("Listen failed");
        exit(1);
    }

    printf("Server is waiting for connections...\n");
    socklen_t cli_len = sizeof(cli);
    c_sd = accept(s_sd, (struct sockaddr *)&cli, &cli_len);
    if (c_sd < 0) {
        perror("Accept failed");
        exit(1);
    }

    while (1) {
        read(c_sd, recv_msg, sizeof(recv_msg));
        printf("\nMessage from client: %s\n", recv_msg);

        printf("Enter message for client: ");
        scanf(" %[^\n]", send_msg);

        write(c_sd, send_msg, sizeof(send_msg));
    }

    close(c_sd);
    close(s_sd);
    return 0;
}