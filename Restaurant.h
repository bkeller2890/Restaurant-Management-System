#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector> 
#include "Employee.h"
#include "Expense.h"
#include "Order.h"

using namespace std;

class Restaurant {
    private:
        string name;
        vector<Employee> employees;
        vector<Expense> expenses;
        vector<Order*> orders;
    public:
        Restaurant(string name);
        ~Restaurant();
        void addEmployee(const Employee& employee);
        void addExpense(const Expense& expense);
        void addOrder(const Order* order);
        double calculateTotalExpenses() const;
        double calculateTotalRevenue() const;
        double calculateProfit() const;
};


#endif // RESTAURANT_H 