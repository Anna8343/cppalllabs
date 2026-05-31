#include <iostream>
using namespace std;

class LazySquare {
    public:
        LazySquare(double side) {
            this -> side = 0;
            this -> area = 0;
            this -> side_changed = true;
            set_side(side);
        }

        void set_side(double s) {
            if (s >= 0) {
                this -> side = s;
                this -> side_changed = true;
            }
        }

        double get_area() {
            if (side_changed) {
                this -> area = side * side;
                this -> side_changed = false;
                cout << "Recalculating area..." << endl;
            }
            return area;
        }

    private:
        double side;
        double area;
        bool side_changed;
};

int main() {
    double side;
    
    cout << "--- Lazy Test ---" << endl;
    
    cout << "Enter the square side value: ";
    cin >> side;
    
    LazySquare lsApp(side);
    
    cout << "\nFirst call: " << lsApp.get_area() << endl;
    
    cout << "Second call: " << lsApp.get_area() << endl;
    
    cout << "\nSet a new square side value: ";
    cin >> side;

    lsApp.set_side(side);
    
    cout << "\nAfter update: " << lsApp.get_area() << endl;
}