#include <iostream>
#include <cstring>
using namespace std;

class Student {
    private:
        char* name;
    public:
        Student(char* n) {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        }
        void displayname() {
            cout << "Name: " << name << "\n";
        }
        void changename(char *n) {
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
