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
       ~Department() {
            delete[] employees;
       }
};

int main() {
    Department d1("AI", "John", 201, 12);
    Department d2 = d1;

    return 0;
}
