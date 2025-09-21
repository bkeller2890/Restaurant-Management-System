#include "Expense.h"
#include <iostream>
#include <string>

using namespace std;

/* 

Expense class: 
    - type 
    - amount 
    - date 

    + getType() : string
    + getAmount() : double
    + getDate() : string
    + OutputExpense() : string
*/

Expense::Expense(string type, double amount, string date){
    this->type = type; 
    this->amount = amount; 
    this->date = date; 
};
string Expense::getType() const {
    return this->type; 
};
double Expense::getAmount() const {
    return this->amount; 
};
string Expense::getDate() const {
    return this->date; 
};

string Expense::OutputExpense() const {
    return "Type: " + type + ", Amount: " + to_string(amount) + ", Date: " + date;
};
