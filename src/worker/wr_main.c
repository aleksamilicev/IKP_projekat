#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "common/network.h"

#define PORT 5060

int main() {
    int server_fd = create_server(PORT);
    printf("Worker is running on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in lb_address;
        socklen_t addr_len = sizeof(lb_address);
        int lb_fd = accept(server_fd, (struct sockaddr*)&lb_address, &addr_len);

        if (lb_fd < 0) {
            perror("Accept failed");
            continue;
        }

        char buffer[1024];
        receive_message(lb_fd, buffer, sizeof(buffer));
        printf("Received from Load Balancer: %s\n", buffer);

        send_message(lb_fd, "Message received by Worker.");
        close(lb_fd);
    }

    close(server_fd);
    return 0;
}
