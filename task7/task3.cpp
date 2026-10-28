#include <iostream>
using namespace std;

class Animal {
public:
    virtual void pet() = 0;
    virtual ~Animal() {}
};

class NPC {
public:
    virtual void talk() = 0;
    virtual ~NPC() {}
};

// Кот одновременно реализует оба интерфейса.
class SmartCat : public Animal, public NPC {
public:
    void pet() {
        cout << "Meow!" << endl;
    }

    void talk() {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* a = new SmartCat();
    a->pet();
    delete a;

    NPC* n = new SmartCat();
    n->talk();
    delete n;
    return 0;
}
