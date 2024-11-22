#ifndef NETWORK_H
#define NETWORK_H

#include <winsock2.h>

// Inicijalizacija Winsock-a
void initialize_winsock();

// Kreira TCP server socket
SOCKET create_server(int port);

// Kreira TCP klijent socket
SOCKET create_client(const char* ip, int port);

// Šalje poruku preko socket-a
void send_message(SOCKET socket, const char* message);

// Prima poruku preko socket-a
void receive_message(SOCKET socket, char* buffer, size_t buffer_size);

// Čisti Winsock resurse
void cleanup_winsock();

#endif // NETWORK_H
