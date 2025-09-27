#include "Restaurant.h"
#include <iostream>


using namespace std;

//TODO: Implement methods to handle employee wages and salaries
//TODO: Implement methods to handle different expense categories
//TODO: Implement methods to handle different order types and their specifics
//TODO: Implement methods to generate financial reports
//TODO: Implement methods to handle taxes and other deductions
//TODO: Implement methods to handle tips and gratuities
//TODO: Implement methods to handle discounts and promotions

Restaurant::Restaurant(string name) : name(name) {}
Restaurant::~Restaurant() {
    for (Order* order: orders){
        delete order;
    }
}
void Restaurant::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}
void Restaurant::addExpense(const Expense& expense) {   
    expenses.push_back(expense);
}
void Restaurant::addOrder(const Order* order) {
    orders.push_back(const_cast<Order*>(order));
}
double Restaurant::calculateTotalExpenses() const {
    double totalExpenses = 0.0;
    for (const auto& expense : expenses) {
        totalExpenses += expense.getAmount();
    }
    for (const auto& employee : employees) {
        totalExpenses += employee.getWage();
    }
    return totalExpenses;
}
double Restaurant::calculateTotalRevenue() const {
    double totalRevenue = 0.0;          
    for (const auto& order : orders) {
        totalRevenue += order->calculateTotal();
    }
    return totalRevenue;
}
double Restaurant::calculateProfit() const {
    return calculateTotalRevenue() - calculateTotalExpenses();
}
