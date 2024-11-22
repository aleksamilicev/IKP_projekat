#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "common/network.h"

#define LB_PORT 5059
#define WR_PORT 5060

void test_lb_to_worker() {
    int lb_client_fd = create_client("127.0.0.1", LB_PORT);
    send_message(lb_client_fd, "Test message from client to Load Balancer.");

    char buffer[1024];
    receive_message(lb_client_fd, buffer, sizeof(buffer));
    printf("Load Balancer response: %s\n", buffer);

    close(lb_client_fd);
}

void test_worker_communication() {
    int worker_client_fd = create_client("127.0.0.1", WR_PORT);
    send_message(worker_client_fd, "Test message from Load Balancer to Worker.");

    char buffer[1024];
    receive_message(worker_client_fd, buffer, sizeof(buffer));
    printf("Worker response: %s\n", buffer);

    close(worker_client_fd);
}

int main() {
    printf("Running integration tests...\n");

    printf("Testing Load Balancer communication:\n");
    test_lb_to_worker();

    printf("Testing Worker communication:\n");
    test_worker_communication();

    return 0;
}
