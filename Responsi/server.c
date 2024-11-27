#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char *message = "Hello, Client!";

    // Langkah 1: Membuat socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error membuat socket");
        return 1;
    }

    // Langkah 2: Bind socket ke port 8080
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error bind socket");
        close(server_fd);
        return 1;
    }

    // Langkah 3: Listen untuk koneksi masuk
    if (listen(server_fd, 1) == -1) {
        perror("Error listen koneksi");
        close(server_fd);
        return 1;
    }
    printf("Server mendengarkan di port 8080...\n");

    // Langkah 4: Terima koneksi
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("Error menerima koneksi");
        close(server_fd);
        return 1;
    }

    // Langkah 5: Kirim pesan ke client
    write(client_fd, message, strlen(message));

    // Langkah 6: Tutup koneksi
    close(client_fd);
    close(server_fd);

    return 0;
}
