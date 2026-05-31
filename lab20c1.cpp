#include <iostream>
using namespace std;

class AdHocSquare {
    public:
        AdHocSquare(double side) {
            set_side(side);
        }

        void set_side(double s) {
            if (s >= 0) {
                this -> side = s;
            }
        }

        double get_area() {
            return side * side;
        }

    private:
        double side;
};

int main() {
    double side;
    
    cout << "--- AdHoc Test ---" << endl;
    
    cout << "Enter the square side value: ";
    cin >> side;
    
    AdHocSquare ahApp(side);
    
    cout << "\nArea: " << ahApp.get_area() << endl;
}