#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        string name;
        int age;
        
        Person(string cus_name = "", int cus_age = 0) {
            name = cus_name;
            age = cus_age;
        }
};

void print(Person* person) {
    cout << person -> name << " is " << person -> age << " years old" << endl << endl;
}

int main() {
    Person person;
    person.name = "Lusi";
    person.age = 23;
    
    cout << "Meet " << person.name << endl;
    print(&person);
    
    Person person2;
    person2.name = "Kate";
    person2.age = 27;
    
    cout << "Meet " << person2.name << endl;
    print(&person2);
    
    Person person3;
    person3.name = "Bob";
    person3.age = 21;
    
    cout << "Meet " << person3.name << endl;
    print(&person3);
    
    return 0;
}