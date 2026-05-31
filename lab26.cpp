#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

class IPAddress {
    protected:
        string address;
    
    public:
        IPAddress(const string& addr) : address(addr) {}
        
        IPAddress(const IPAddress& other) : address(other.address) {}
        
        virtual ~IPAddress() = default;
        
        virtual void print() const {
            cout << address;
        }
};

class IPAddressChecked : public IPAddress {
    private:
        bool is_correct;
        
        bool validateIP(const string& addr) {
            stringstream ss(addr);
            string segment;
            int segmentCount = 0;
            
            while (getline(ss, segment, '.')) {
                segmentCount++;
                if (segment.empty() || segment.length() > 3) return false;
                for (char c : segment) {
                    if (!isdigit(c)) return false;
                }
                int value = stoi(segment);
                if (value < 0 || value > 255) return false;
            }
            
            return segmentCount == 4;
        }

    public:
        IPAddressChecked(const string& addr) : IPAddress(addr) {
            is_correct = validateIP(addr);
        }
        
        IPAddressChecked(const IPAddressChecked& other) 
            : IPAddress(other), is_correct(other.is_correct) {}
        
        void print() const override {
            IPAddress::print();
            if (is_correct) {
                cout << " - Correct";
            } else {
                cout << " - Not Correct";
            }
        }
};

int main() {
    string input1, input2, input3;
    cin >> input1 >> input2 >> input3;

    IPAddress ip1(input1);
    IPAddressChecked ip2(input2);
    IPAddressChecked ip3(input3);

    ip1.print(); cout << endl;
    ip2.print(); cout << endl;
    ip3.print(); cout << endl;

    return 0;
}