#include <iostream>
using namespace std;

class Item {
    private:
        static double value;
    public:
        static double func() {
            return value;
        } 
};

double Item :: value{10.5};

int main() {
    cout << "Value: " << Item :: func() << endl;

}
