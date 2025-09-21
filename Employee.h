#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
    private:
        string name;
        string position;
        int id; 
        double wage;
    public:
        Employee(string name, string position, int id, double salary);
        string getName() const;
        string getPosition() const;
        int getId() const;
        double getWage() const;
}; 


#endif // EMPLOYEE_H