#include <iostream>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    int maxSeats = (int)(capacity * 1.05);
    if (reserved < 0) this->reserved = 0;
    else if (reserved > maxSeats) this->reserved = maxSeats;
    else this->reserved = reserved;
}

void FlightBooking::printStatus() {
    int percentage = 0;
    if (capacity > 0) {
        percentage = (reserved * 100) / capacity;
    }
    cout << "Flight " << id << " : " << reserved << "/" << capacity
         << " (" << percentage << "%) seats reserved" << endl;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    if (number_of_seats < 0) return false;
    int maxSeats = (int)(capacity * 1.05);
    if (reserved + number_of_seats <= maxSeats) {
        reserved += number_of_seats;
        return true;
    }
    return false;
}

bool FlightBooking::cancelReservations(int number_of_seats) {
    if (number_of_seats < 0 || reserved - number_of_seats < 0) return false;
    reserved -= number_of_seats;
    return true;
}

int main() {
    int reserved = 0, capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;

    FlightBooking booking(1, capacity, reserved);
    string command = "";

    while (true) {
        booking.printStatus();
        cout << "What would you like to do?: ";
        cin >> command;

        if (command == "quit") break;

        int amount;
        if (command == "add") {
            cin >> amount;
            if (!booking.reserveSeats(amount))
                cout << "Cannot perform this operation" << endl;
        } else if (command == "cancel") {
            cin >> amount;
            if (!booking.cancelReservations(amount))
                cout << "Cannot perform this operation" << endl;
        }
    }
    return 0;
}