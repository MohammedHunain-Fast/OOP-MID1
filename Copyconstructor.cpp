#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        string name;
        int age;
    public:
        Student(string name, int age) {
            this -> name = name;
            this -> age = age;
        }
        Student(const Student& s) {
            name = s.name;
            age = s.age;
        }

        void display() {
            cout << name << "\n" << age << "\n";
        }
};

int main() {
    Student s1("Bob", 20);
    s1.display();
    Student s2 = s1;
    s2.display();

};
