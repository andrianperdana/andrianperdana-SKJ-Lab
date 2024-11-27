#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};

    // Langkah 1: Membuat socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        perror("Error membuat socket");
        return 1;
    }

    // Langkah 2: Tentukan alamat server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Langkah 3: Terhubung ke server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error koneksi ke server");
        close(client_fd);
        return 1;
    }

    // Langkah 4: Terima pesan dari server
    read(client_fd, buffer, sizeof(buffer));
    printf("Diterima dari server: %s\n", buffer);

    // Langkah 5: Tutup koneksi
    close(client_fd);

    return 0;
}
