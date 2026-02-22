#include <iostream>
#include <string>
using namespace std;

class Student {
        string name;
        int age;
    public:
        void setdata(string name, int age) {
            this -> name = name;
            this -> age = age;
        }

        void display() {
            cout  <<  "name: " << name <<  "\n" << "Age: " << age  << "\n"; 

        }

        void modifydata(Student& s, string name, int age) {
            s.setdata(name, age);
            s.display();
        }

};

int main() {
    Student s1;
    cout << "Before call!\n";
    s1.setdata("Bob", 20);
    s1.display();
    cout << "After call!\n";
    s1.modifydata(s1 ,"Bob", 21);
    s1.display();

}
