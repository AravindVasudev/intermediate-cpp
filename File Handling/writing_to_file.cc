#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string str, filename;

    std::cout << "Enter some text: ";
    std::getline(std::cin, str);

    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::ofstream of(filename, std::ios::app);
    of << str;
    of.close();

    std::cout << "Written.\n";

    return 0;
}