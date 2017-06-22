#include<iostream>
#include<array>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::sort;

int main() {
    array<int, 10> my_array;
    int n;

    for (int i = 0, j = 10; i < 10 && j > 0; i++, j--) {
        my_array[i] = j;
    }

    for (int i = 0; i < my_array.size(); i++) {
        cout << my_array[i] << " ";
    }

    cout << "\nSorted:\n";
    sort(my_array.begin(), my_array.end());
    for (int i = 0; i < my_array.size(); i++) {
        cout << my_array[i] << " ";
    }
}
