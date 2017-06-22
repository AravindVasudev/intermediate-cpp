#include <iostream>
#include <map>

int main() {
    std::multimap<int, int> mmap;

    for (int i = 0, j = 10; i < 10; i++, j--) {
        mmap.insert(std::pair<int, int>(i, j));
    }

    std::cout << "Key Value\n";
    for (auto it = mmap.begin(); it != mmap.end(); it++) {
        std::cout << it->first << "   " << it->second << "\n";
    }

    std::cout << "Size: " << mmap.size() << std::endl;
    std::cout << "3: " << mmap.find(3)->second;
}
