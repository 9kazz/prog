#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};

class ZooKeeper {
private:
    int dangerousCount;

public:
    ZooKeeper() {
        dangerousCount = 0;
    }

    void handleAnimal(Animal* a) {
        // Для любого зверя используем один и тот же интерфейс.
        if (a->isDangerous()) {
            dangerousCount++;
        }
    }

    int getDangerousCount() {
        return dangerousCount;
    }
};

// Эти два класса нужны для примера из задания.
class Monkey : public Animal {
public:
    string getType() {
        return "Monkey";
    }

    bool isDangerous() {
        return false;
    }
};

class Lion : public Animal {
public:
    string getType() {
        return "Lion";
    }

    bool isDangerous() {
        return true;
    }
};

int main() {
    ZooKeeper z;
    Monkey m1;
    Monkey m2;
    Lion l;
    z.handleAnimal(&m1);
    z.handleAnimal(&m2);
    z.handleAnimal(&l);
    cout << z.getDangerousCount() << endl;
    return 0;
}
