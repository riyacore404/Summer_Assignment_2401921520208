#include <iostream>
using namespace std;

// Interface
class Test {
public:
    virtual int square(int x) = 0;
};

// Arithmetic class implementing Test
class Arithmetic : public Test {
public:
    int square(int x) override {
        return x * x;
    }
};

// ToTestInt class
class ToTestInt {
public:
    void displaySquare(int n) {
        Arithmetic obj;
        cout << "Square = " << obj.square(n) << endl;
    }
};

int main() {
    ToTestInt t;
    t.displaySquare(5);

    return 0;
}