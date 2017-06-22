#include<iostream>
#include<stack>

int main() {
    std::stack<int> mystack;

    for (int i = 0; i < 10; i++) {
        mystack.push(i);
    }

    std::cout << "Stack size: " << mystack.size() << std::endl;
    while (!mystack.empty()) {
        std::cout << mystack.top() << " ";
        mystack.pop();
    }
}
