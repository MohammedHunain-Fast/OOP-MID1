#include <iostream>
#include <string>
using namespace std;

int main() {
    int n  = 0;
    cout  << "Enter n: ";
    cin >> n;
    int *pArr = new int[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter element" << i + 1 << ": ";
        cin >> pArr[i];
    }

    for(int i = 0; i < n; i++) {
        cout << i + 1 << "." << "Element" << ": " << pArr[i] << "\n";
    }

    delete[] pArr;
}
