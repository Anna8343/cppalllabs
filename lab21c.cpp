#include <iostream>
#include <string>
using namespace std;

class FlightBooking {
    public:
        FlightBooking(int id, int capacity, int reserved);
        FlightBooking();
        void printStatus();
        bool reserveSeats(int number_of_seats);
        bool cancelReservations(int number_of_seats);
        int getId() { return id; }
    private:
        int id;
        int capacity;
        int reserved;
};

FlightBooking::FlightBooking() {
    id = 0;
    capacity = 0;
    reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this -> id = id;
    this -> capacity = (capacity < 0) ? 0 : capacity;

    double max_allowed = this -> capacity * 1.05;
    if (reserved < 0) this -> reserved = 0;
    else if (reserved > max_allowed) this -> reserved = (int)max_allowed;
    else this -> reserved = reserved;
}

void FlightBooking::printStatus() {
    if (id == 0) return;
    double percentage = 0;
    if (capacity > 0) percentage = (reserved * 100.0) / capacity;
    
    cout << "Flight " << id << " : " << reserved << "/" << capacity 
         << " (" << percentage << "%) seats reserved" << endl;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    if (number_of_seats < 0) return false;
    if (reserved + number_of_seats <= capacity * 1.05) {
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

void printAll(FlightBooking flights[], int size) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (flights[i].getId() != 0) {
            flights[i].printStatus();
            found = true;
        }
    }
    if (!found) cout << "No flights in the system" << endl;
}

int main() {
    FlightBooking flights[10]; 
    string command;

    while (true) {
        printAll(flights, 10);
        cout << "What would you like to do?: ";
        if (!(cin >> command) || command == "quit") break;

        if (command == "create") {
            int id, cap;
            cin >> id >> cap;
            bool created = false;
            for (int i = 0; i < 10; i++) {
                if (flights[i].getId() == 0) {
                    flights[i] = FlightBooking(id, cap, 0);
                    created = true;
                    break;
                }
            }
            if (!created) cout << "Cannot perform this operation: system full" << endl;
        } 
        else if (command == "delete") {
            int id;
            cin >> id;
            bool deleted = false;
            for (int i = 0; i < 10; i++) {
                if (flights[i].getId() == id) {
                    flights[i] = FlightBooking();
                    deleted = true;
                    break;
                }
            }
            if (!deleted) cout << "Cannot perform this operation: flight " << id << " not found" << endl;
        } 
        else if (command == "add") {
            int id, n;
            cin >> id >> n;
            bool found = false;
            for (int i = 0; i < 10; i++) {
                if (flights[i].getId() == id) {
                    if (!flights[i].reserveSeats(n)) cout << "Cannot perform this operation: capacity reached" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Cannot perform this operation: flight " << id << " not found" << endl;
        } 
        else if (command == "cancel") {
            int id, n;
            cin >> id >> n;
            bool found = false;
            for (int i = 0; i < 10; i++) {
                if (flights[i].getId() == id) {
                    if (!flights[i].cancelReservations(n)) cout << "Cannot perform this operation" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Cannot perform this operation: flight " << id << " not found" << endl;
        }
    }
    return 0;
}