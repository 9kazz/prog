#include <iostream>
using namespace std;

class Train {
private:
    double mass;
    double speed;
    double x;

public:
    Train(double m) {
        mass = m;
        speed = 0;
        x = 0;
    }

    void move(double dt) {
        x += speed * dt;
    }

    void accelerate(double dp) {
        // Изменение импульса меняет скорость на dp / mass.
        speed += dp / mass;
    }

    double getX() {
        return x;
    }
};

int main() {
    Train t(10);
    t.accelerate(1);
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.move(1);
    cout << "Current X: " << t.getX() << endl;
    t.accelerate(-2);
    t.move(3);
    cout << "Current X: " << t.getX() << endl;
    return 0;
}
