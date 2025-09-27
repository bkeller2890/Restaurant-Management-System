#include "Employee.h"
#include <string>
using namespace std;

//TODO: Implement methods to handle employee wages and salaries
//TODO: Implement methods to handle employee roles and permissions
//TODO: Implement methods to handle employee schedules and shifts
//TODO: Implement methods to handle employee performance reviews
//TODO: Implement methods to handle employee benefits and deductions
//TODO: Implement methods to handle employee contact information
//TODO: Implement methods to handle employee hiring and termination
//TODO: Implement methods to handle employee training

Employee::Employee(string name, string position, int id, double wage){
    this->name = name; 
    this->position = position; 
    this->id = id; 
    this->wage = wage; 
};
string Employee::getName() const {
    return this->name; 
};
string Employee::getPosition() const {
    return this->position;
};
int Employee::getId() const {
    return this->id; 
};
double Employee::getWage() const {
    return this->wage; 
};  
        