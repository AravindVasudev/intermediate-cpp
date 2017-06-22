#include<iostream>
#include<list>

using std::cout;
using std::cin;
using std::list;

int main() {
	list<int> myList(5, 1);

	for (int i = 0; i < 10; i++) {
		myList.push_back(i);
	}

	cout << myList.front() << myList.back();

	myList.pop_back();
	myList.pop_front();

	list<int>::iterator i1 = myList.begin();
	advance(i1, 3);
	myList.erase(i1);

	for (int i : myList) {
		cout << i << " ";
	}

}
