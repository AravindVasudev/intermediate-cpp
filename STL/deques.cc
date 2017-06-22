#include<iostream>
#include<deque>

int main() {
	std::deque<int> my_deque(5, 0); // {0, 0, 0, 0, 0}

	for (int i = 0; i < 10; i++) {
		my_deque.push_back(i);
	}

	for (int i = 10; i > 0; i--) {
		my_deque.push_front(i);
	}

	std::cout << my_deque.size() << std::endl;
	my_deque.pop_back();
	std::cout	<< my_deque.size() << std::endl;

	for (int i : my_deque) {
		std::cout << i << " ";
	}
}
