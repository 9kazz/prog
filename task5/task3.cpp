#include <iostream>
using namespace std;

class SpacePort {
private:
    unsigned int size;
    bool* occupied;

public:
    SpacePort(unsigned int size) {
        this->size = size;
        occupied = new bool[size];
        for (unsigned int i = 0; i < size; i++) {
            occupied[i] = false;
        }
    }

    ~SpacePort() {
        delete[] occupied;
    }

    bool requestLanding(unsigned int dockNumber) {
        // Сначала проверяем номер, затем занятость дока.
        if (dockNumber >= size || occupied[dockNumber]) {
            return false;
        }
        occupied[dockNumber] = true;
        return true;
    }

    bool requestTakeoff(unsigned int dockNumber) {
        if (dockNumber >= size || !occupied[dockNumber]) {
            return false;
        }
        occupied[dockNumber] = false;
        return true;
    }
};

int main() {
    SpacePort s(5);
    cout << boolalpha << s.requestLanding(0) << endl;
    cout << boolalpha << s.requestLanding(4) << endl;
    cout << boolalpha << s.requestLanding(5) << endl;
    cout << boolalpha << s.requestTakeoff(0) << endl;
    cout << boolalpha << s.requestTakeoff(4) << endl;
    cout << boolalpha << s.requestTakeoff(5) << endl;
    return 0;
}
