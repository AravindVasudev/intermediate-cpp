#include<iostream>
#include<map>
#include<iterator>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::iterator;
using std::pair;

int main() {
    map<int, int> my_map;

    for (int i = 0, j = 10; i < 10 && j > 0; i++, j--) {
        my_map.insert(pair<int, int>(i, j));
    }

    cout << "Key\tValue\n";
    for (pair<int, int> i : my_map) {
        cout << i.first << "\t" << i.second << endl;
    }

    cout << "3: " << my_map[3] << "\nCount for 3: " << my_map.count(3);
    my_map.erase(3);
    my_map.erase(5);

    cout << "\nKey\tValue\n";
    for (map<int, int>::iterator itr = my_map.begin(); itr != my_map.end(); itr++) {
        cout << itr->first << "\t" << itr->second << endl;
    }
}
