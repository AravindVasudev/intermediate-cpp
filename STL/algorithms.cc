#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::vector<int> vec;
    std::map<char, int> dict;

    // Populate vector and map
    for (int i = 0, j = 10; i < 10; i++, j--) {
        vec.push_back(i);
        dict.insert(std::pair<int, int>(i, j));
    }

    // Print the collections
    std::cout << "Vector:\n";
    for (int i : vec) {
        std::cout << i << " ";
    }

    std::cout << "\nMap:\n";
    for (std::pair<int, int> i : dict) {
        std::cout << i.first << ":" << i.second << " ";
    }

    // all_of - takes begin iterator, end iterator and a function and returns
    // true if the function returns true for all elements
    if ( std::all_of(vec.begin(), vec.end(), [](int i){ return i >= 0; }) ) {
        std::cout << "\nAll elements are positive";
    } else {
        std::cout << "\nAll elements are not positive";
    }

    // for_each - applies a function to a range
    std::cout << "\nVector * 2:\n";
    std::for_each (vec.begin(), vec.end(), [](int i){std::cout << i * 2 << " ";});

    // count - counts the occurence of an element in the range
    std::cout << "\ncount(1): " << std::count(vec.begin(), vec.end(), 1);
}
