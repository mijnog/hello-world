//GPT GENERATED CODE
//BE VERY CAREFUL
//DO NOT USE THIS AT HOME

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 80
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char *response_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    ssize_t bytes_read;
    
    // Receive HTTP request
    bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_read < 0) {
        perror("Error reading from socket");
        return;
    }
    
    // Extract filename from request
    char *filename = strtok(buffer, " ");
    filename = strtok(NULL, " ");
    if (strcmp(filename, "/") == 0) {
        filename = "index.html"; // Default file to serve
    } else {
        filename++; // Skip leading '/'
    }
    
    // Open and read the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    // Send HTTP response header
    send(client_socket, response_header, strlen(response_header), 0);
    
    // Send file content
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        send(client_socket, buffer, bytes_read, 0);
    }
    
    // Close file and client socket
    fclose(file);
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 5) < 0) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connections
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Handle client request
        handle_client(client_socket);
    }

    return 0;
}