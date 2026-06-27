#include <iostream>
using namespace std;

class Box {
protected:
    int length, breadth;

public:
    Box(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }
};

class Box3D : public Box {
private:
    int height;

public:
    Box3D(int l, int b, int h) : Box(l, b) {
        height = h;
    }

    int volume() {
        return length * breadth * height;
    }
};

int main() {
    Box b(5, 4);
    cout << "Area = " << b.area() << endl;

    Box3D b3(5, 4, 3);
    cout << "Area = " << b3.area() << endl;
    cout << "Volume = " << b3.volume() << endl;

    return 0;
}