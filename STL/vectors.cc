#include<iostream>
#include<vector>

int main() {
	std::vector<int> vec;
	int input;

	std::cout << "Enter the elements:\n";
	while (std::cin >> input) {
		vec.push_back(input);
	}

	std::cout << "Number of Elements: " << vec.size() << "\nThe Elements are:\n";
	for(int item : vec) {
		std::cout << item << " ";
	}
}
