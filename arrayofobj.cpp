#include <iostream>
#include <string>
using namespace std;

class Students {
    private:
        string name;
        int age;
    public:
        void setdata(string name, int age) {
            this -> name = name;
            this -> age = age;
        }

        void displaydata() {
            cout << "Name: " << name << endl << "Age: " << age << endl;
        }

};

int main() {
    Students s[2];

    s[0].setdata("Bob", 19);
    s[1].setdata("Alice", 20);

    for(int i = 0; i < 2; i++) s[i].displaydata();


    return 0;
}
