#include <iostream>
#include <cstring>
using namespace std;

class Student {
    private:
        char* name;
    public:
        Student(const char* n) {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        }
        Student(const Student& s) {
            name = new char[strlen(s.name) + 1];
            strcpy(name, s.name);
        }
        void displayname() {
            cout << "Name: " << name << "\n";
        }
        void changename(const char *n) {
            strcpy(name, n);
        };
        ~Student() {
            delete[] name;
        }
};

int main() {
    Student s1("John");
    Student s2 = s1;
    s1.displayname();
    s2.displayname();
    s2.changename("Bob");
    s1.displayname();
    s2.displayname();
    
    return 0;
}
