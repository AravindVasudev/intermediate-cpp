#include <iostream>
#include <thread>
#include <chrono>

void thread_function(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "Slept for " << n << "seconds.\n";
}

int main(int argc, char **argv) {
    std::cout << "Spawning 3 threads...\n";

    std::thread t1(thread_function, 5);
    std::thread t2(thread_function, 4);
    std::thread t3(thread_function, 6);

    std::cout << "Done spawning. waiting for threads to join.\n";

    t1.join();
    t2.join();
    t3.join();

    std::cout << "All threads joined!\n";

    return 0;
}
