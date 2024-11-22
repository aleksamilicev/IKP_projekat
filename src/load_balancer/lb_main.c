#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "common/network.h"

#define PORT 5059

int main() {
    int server_fd = create_server(PORT);
    printf("Load Balancer is running on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in client_address;
        socklen_t addr_len = sizeof(client_address);
        int client_fd = accept(server_fd, (struct sockaddr*)&client_address, &addr_len);

        if (client_fd < 0) {
            perror("Accept failed");
            continue;
        }

        char buffer[1024];
        receive_message(client_fd, buffer, sizeof(buffer));
        printf("Received from client: %s\n", buffer);

        send_message(client_fd, "Message received by Load Balancer.");
        close(client_fd);
    }

    close(server_fd);
    return 0;
}
