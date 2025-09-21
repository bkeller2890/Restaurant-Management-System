#include "Order.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;    

//TODO: Implement time functionality for orderTime
//TODO: Implement receipt formatting
//TODO: Implement commission calculation for DeliveryOrder
//TODO: Implement tax calculation if needed
//TODO: Implement discounts or promotions if needed
//TODO: Implement item quantity if needed
//TODO: Implement order status if needed
//TODO: Implement customer details if needed

Order::Order(int id) : orderID(id), totalAmount(0.0) {
    // Initialize order time to current time (placeholder)
    orderTime = "2024-01-01 12:00"; // This should be replaced with actual timestamp logic
}
Order::~Order() {
    // Destructor logic if needed
}
void Order::addItem(const MenuItem& item) {
    items.push_back(item);
}
double Order::calculateTotal() {
    totalAmount = 0.0;
    for (const auto& item : items) {
        totalAmount += item.getPrice();
    }
    return totalAmount;
}

void Order::printReceipt() const {
    // Base class does not implement this
}   
DineInOrder::DineInOrder(int id, int tableNum) : Order(id), tableNumber(tableNum) {}
void DineInOrder::printReceipt() const {
    cout << "Dine-In Order Receipt" << endl;
    cout << "Order ID: " << orderID << endl;
    cout << "Table Number: " << tableNumber << endl;
    cout << "Items:" << endl;
    for (const auto& item : items) {
        cout << "- " << item.getName() << ": $" << fixed << setprecision(2) << item.getPrice() << endl;
    }
    cout << "Total: $" << fixed << setprecision(2) << totalAmount << endl;
    cout << "Thank you for dining with us!" << endl;
}                   
DriveThruOrder::DriveThruOrder(int id) : Order(id) {}
void DriveThruOrder::printReceipt() const {
    cout << "Drive-Thru Order Receipt" << endl;
    cout << "Order ID: " << orderID << endl;
    cout << "Items:" << endl;
    for (const auto& item : items) {
        cout << "- " << item.getName() << ": $" << fixed << setprecision(2) << item.getPrice() << endl;
    }
    cout << "Total: $" << fixed << setprecision(2) << totalAmount << endl;
    cout << "Thank you for your order!" << endl;
}                   
TakeOutOrder::TakeOutOrder(int id) : Order(id) {
}
void TakeOutOrder::printReceipt() const {
    cout << "Take-Out Order Receipt" << endl;
    cout << "Order ID: " << orderID << endl;
    cout << "Items: " << endl;
    for (const auto& item : items) {
        cout << "- " << item.getName() << ": $" << fixed << setprecision(2) << item.getPrice() << endl;
    }
    cout << "Total: $" << fixed << setprecision(2) << totalAmount << "\n";
    cout << "Thank you for your order!" << endl;
}           

DeliveryOrder::DeliveryOrder(int id, string platform, double commission) 
    : Order(id), platformName(platform), commissionRate(commission) {}      
double DeliveryOrder::calculateTotal() {
    double baseTotal = Order::calculateTotal();
    double commission = baseTotal * commissionRate;
    totalAmount = baseTotal + commission;
    return totalAmount;
}
void DeliveryOrder::printReceipt() const {
    cout << "Delivery Order Receipt" << endl; 
    cout << "Order ID: " << orderID << endl;
    cout << "Platform: " << platformName << endl;
    cout << "Items:" << endl;
    for (const auto& item : items) {
        cout << "- " << item.getName() << ": $" << fixed << setprecision(2) << item.getPrice() << endl;
    }
    double baseTotal = 0.0;
    for (const auto& item : items) {
        baseTotal += item.getPrice();
    }
    double commission = baseTotal * commissionRate;             
    cout << "Subtotal: $" << fixed << setprecision(2) << baseTotal << endl;
    cout << "Commission (" << commissionRate * 100 << "%): $" << fixed << setprecision(2) << commission << endl;
    cout << "Total: $" << fixed << setprecision(2) << totalAmount << endl;
    cout << "Thank you for your order!" << endl; 
}