#include <iostream>
using namespace std;

// Эмуляция библиотек из условия.
namespace namespaceA {
    class Engine {
    public:
        void run() {
            cout << "EngineA run" << endl;
        }
    };
}

namespace namespaceB {
    class Engine {
    public:
        void run() {
            cout << "EngineB run" << endl;
        }
    };
}

namespace namespaceC {
    class Engine {
    public:
        void run() {
            cout << "EngineC run" << endl;
        }
    };
}

class MyEngine {
private:
    namespaceA::Engine a;
    namespaceB::Engine b;
    namespaceC::Engine c;

public:
    void run(unsigned int number) {
        // По номеру выбираем нужный движок.
        if (number == 1) {
            a.run();
        } else if (number == 2) {
            b.run();
        } else if (number == 3) {
            c.run();
        }
    }
};

int main() {
    MyEngine e;
    e.run(1);
    e.run(2);
    e.run(3);
    e.run(10);
    return 0;
}
