#include<iostream>
#include<forward_list>

int main() {
    std::forward_list<int> flist;

    flist.assign({1, 2, 3});
    for (int i = 0, j = 10; i < 10; i++, j--) {
        if (i & 1) flist.push_front(i);
        else flist.push_front(j);
    }

    for (std::forward_list<int>::iterator i = flist.begin(); i != flist.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

   auto it = flist.begin();
   advance(it, 3);
   flist.erase_after(it, flist.end());
    for (std::forward_list<int>::iterator i = flist.begin(); i != flist.end(); i++) {
        std::cout << *i << " ";
    }
}
