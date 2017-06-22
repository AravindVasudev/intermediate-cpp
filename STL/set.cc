#include<iostream>
#include<array>
#include<set>

int main() {
    std::array<int, 20> arr = {1, 1, 2, 3, 4, 5, 4, 3, 2, 2, 3, 6, 7, 8, 9, 9, 9, 9, 15, 15};
    std::set<int> myset(arr.begin(), arr.end());

    for (int i = 0; i < 10; i++) {
        myset.insert(i);
    }

    for (auto i = myset.begin(); i != myset.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}
