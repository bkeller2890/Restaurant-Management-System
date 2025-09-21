#include "Employee.h"
#include "Expense.h"
#include "MenuItem.h"
#include "Order.h"
#include "Restaurant.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

    //TODO: Implement file I/O for persistent data storage 


    // Create a restaurant
    Restaurant myRestaurant("Gourmet Haven");   
    // Add employees
    Employee emp1("Alice Johnson", "Chef", 1, 50000);
    Employee emp2("Bob Smith", "Waiter", 2, 30000);
    myRestaurant.addEmployee(emp1);
    myRestaurant.addEmployee(emp2);

    // Add expenses
    //NOte: 
    Expense exp1("Rent", 2000, "2024-01-01");


    Expense exp2("Utilities", 300, "2024-01-05");
    myRestaurant.addExpense(exp1);
    myRestaurant.addExpense(exp2);
    // Add menu items
    //TODO: Implement different categories of item sizes (e.g., small, medium, large)
    MenuItem item1("Burger", "Gourmet Burger", 10.99,5.00);  
    MenuItem item2("Fries", "Fries", 3.49, 1.00);
    MenuItem item3("Soda", "Unlimited Refill Soda", 1.99, 0.50);
    // Create and add orders - More orders can be added similarly
    // 
    DineInOrder* order1 = new DineInOrder(101, 5);
    DineInOrder* order2 = new DineInOrder(97, 10);
    
    //TODO: Implement item quantities in orders, also consider implementing combo meals
    order1->addItem(item1);
    order1->addItem(item2);
    order1->addItem(item3);
    order1->calculateTotal();
    myRestaurant.addOrder(order1);          

    DriveThruOrder* order2 = new DriveThruOrder(102);
    order2->addItem(item2);
    order2->addItem(item3);
    order2->calculateTotal();
    myRestaurant.addOrder(order2);
    // Calculate and display financials
    cout << "Total Expenses: $" << myRestaurant.calculateTotalExpenses() << endl;
    cout << "Total Revenue: $" << myRestaurant.calculateTotalRevenue() << endl;
    cout << "Total Profit: $" << myRestaurant.calculateProfit() << endl;    


    //delete dynamically allocated orders
    delete order1;
    delete order2;
    

    return 0; 
}