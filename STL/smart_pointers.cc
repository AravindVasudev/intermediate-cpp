#include <iostream>
#include <memory>

class Dummy {
public:
    Dummy() {
        std::cout << "Constructor called\n";
    }

    std::string print() {
        return "wubba lubba dub dub\n";
    }

    ~Dummy() {
        std::cout << "Destructor called\n";
    }
};

int main() {
    {
    std::unique_ptr<Dummy> ptr = std::make_unique<Dummy>();
    std::cout << ptr->print();
    }

    std::weak_ptr<Dummy> ref;
    {
        std::shared_ptr<Dummy> copied;
        {
            std::shared_ptr<Dummy> ptr = std::make_shared<Dummy>();
            copied = ptr;
            ref = ptr;

            std::cout << ptr->print();
        }
        std::cout << copied->print();
    }

    std::cout << "End of Main\n";
}