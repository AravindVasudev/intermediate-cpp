#include<iostream>
#include<queue>

int main() {
    std::priority_queue<int> pq;

    for (int i = 0; i < 30; i += 2) {
        pq.push(i);
    }

    std::cout << "Queue Size: " << pq.size() << std::endl;
    while(!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";
}
