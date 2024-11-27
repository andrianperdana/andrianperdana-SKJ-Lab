#include <iostream>
#include <thread>
#include <unistd.h> // Untuk fungsi sleep

void threadFunction() {
    sleep(1); // Tidur selama 1 detik
    printf("hello\n");
}

int main() {
    // Membuat thread
    std::thread t(threadFunction);

    // Tunggu thread selesai
    t.join();

    return 0;
}
