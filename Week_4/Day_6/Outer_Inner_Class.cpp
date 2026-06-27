#include <iostream>
using namespace std;

class Outer {
public:
    void display() {
        cout << "Display function of Outer class" << endl;
    }

    class Inner {
    public:
        void display() {
            cout << "Display function of Inner class" << endl;
        }
    };
};

int main() {
    Outer o;
    Outer::Inner i;

    o.display();
    i.display();

    return 0;
}