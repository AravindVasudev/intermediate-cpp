#include<iostream>
#include<queue>

int main() {
    std::queue<int> myqueue;

    for (int i = 0; i < 10; i++) {
        myqueue.push(i);
    }

    std::cout << "Queue Size: " << myqueue.size() << std::endl;
    while(!myqueue.empty()) {
        std::cout << myqueue.front() << ' ';
        myqueue.pop();
    }

    std::cout << "\n";
}
