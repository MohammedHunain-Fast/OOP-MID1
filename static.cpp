#include <iostream>
using namespace std;

class Student {
    public:
        int normalcount = 0;
        static int staticcount;

        Student() {
            normalcount++;
            staticcount++;
        }
};

int Student :: staticcount{0};

int main() {
cout << Student::staticcount << endl;

    Student s1,  s2, s3;

    cout << s1.normalcount << endl;
    cout << s2.normalcount << endl;
    cout << s3.normalcount << endl;
    cout << Student::staticcount << endl;



}
