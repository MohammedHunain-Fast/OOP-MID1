#include <iostream>
using namespace std;

class Employee {
        string name;
        int id;
    public:
        Employee() {
            name = "Unknown";
            id = 0; 
        };
        Employee(int id, string name) : id(id), name(name) {};
};

class Department {
    private:
        string name;
        Employee HoD;
        int numEmployees;
        int maxEmployees;
        Employee* employees;
    public:
       Department(string name, string managerName, int managerID, int maxEmployees) : name(name), HoD(managerID, managerName), numEmployees(0), maxEmployees(maxEmployees) {
            employees = new Employee[maxEmployees];
       };
       Department(const Department& d) : name(d.name), HoD(d.HoD), numEmployees(d.numEmployees), maxEmployees(d.maxEmployees)  {
            employees = new Employee[maxEmployees];
            for(int i = 0; i < numEmployees; i++) {
                employees[i] = d.employees[i];
            }
       } 

     void addEmployee(int id, string name) {
        if (numEmployees < maxEmployees) {
            employees[numEmployees] = Employee(id, name);
            numEmployees++; 
        } 
        else {
            cout << "Error: Department " << name << " is full!" << endl;
        }

} 
       ~Department() {
            delete[] employees;
       }
};

int main() {
    Department d1("AI", "John", 201, 1);
    d1.addEmployee(101, "Alice");
    d1.addEmployee(102, "bob");
    Department d2 = d1;


    return 0;
}
