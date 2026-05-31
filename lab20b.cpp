#include <iostream>
#include <string>
using namespace std;

class Square {
    private:
        double side;
        double area;
    
    public:
        Square(double side) {
            this -> side = 0;
            this -> area = 0;
            set_side(side);
        }
        
        void set_side(double s) {
            if (s >= 0) {
                side = s;
                area = s * s;
            }
        }
        
        void print() {
            cout << "Square: side = " << side << " area = " << area << endl;
        }
};

int main() {
    Square s(4);
    s.print();
    
    s.set_side(2.16);
    s.print();
    
    s.set_side(-33.7);
    s.print();
    
    return 0;
}