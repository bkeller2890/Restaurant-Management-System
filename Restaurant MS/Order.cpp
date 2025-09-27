#include "Order.h"
#include "DateTimeFormatter.h"
#include <iostream>
#include <iomanip>
#include <utility> 
#include <vector> 
#include <string>
#include <ctime>
#include <chrono>
#include <cmath>
#include <cstdlib>

using namespace std;    

//TODO: Implement time functionality for orderTime

namespace {
    using namespace std::chrono;
    // Reuse DateTimeFormatter functions for formatting
}


//TODO: Implement discounts or promotions if needed
//TODO: Implement item quantity if needed
//TODO: Implement order status if needed
//TODO: Implement customer details if needed

Order::Order(int id) : orderID(id), totalAmount(0.0) {
    // store the time_point
    orderTime = chrono::system_clock::now();
    // determine timezone offset (local - UTC) in seconds
    time_t now_time = chrono::system_clock::to_time_t(orderTime);
    
    /*
     ===============================================================================
     NOTE: Order.cpp should ideally be using localtime_r/gmtime_r for thread safety
     as it appears in the existing Order.cpp file.
     The following assumes a POSIX-like environment where these are available.
     If not, it falls back to the less safe std::localtime/std::gmtime which
     the DateTimeFormatter::getLocalTm uses.
     ===============================================================================
    */
    
    tm local_tm_storage{};
    tm gm_tm_storage{};
    tm* local_tm = localtime_r(&now_time, &local_tm_storage);
    tm* gm_tm = gmtime_r(&now_time, &gm_tm_storage);
    // compute offsets as seconds since epoch for each tm
    time_t local_secs = mktime(local_tm);
    time_t gm_secs = mktime(gm_tm);
    timezoneOffsetSeconds = static_cast<int>(difftime(local_secs, gm_secs));
    // try to get timezone name from environment or tm fields
    tzset(); // initialize timezone data
    const char* tzenv = getenv("TZ");
    if (tzenv && tzenv[0] != '\0') {
        timezoneName = string(tzenv);
    } else if (local_tm && local_tm->tm_zone) {
        timezoneName = string(local_tm->tm_zone);
    } else {
        // fallback to tzname if available
        extern char* tzname[];
        timezoneName = tzname[0] ? string(tzname[0]) : string("local");
    }
}
Order::~Order() {
    // Destructor logic if needed
}
void Order::addItem(const MenuItem& item, int quantity) {
    OrderItem newItem = {item, quantity};
    items.push_back(newItem);
}
double Order::calculateTotal() {
    totalAmount = 0.0;
    for (const auto& entry : items) {
        totalAmount += entry.item.getPrice() * entry.quantity;
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
    // Print only local date-time
    cout << "Order Time: " << DateTimeFormatter::formatLocalTime(orderTime) << endl;
    cout << "Table Number: " << tableNumber << endl;
    cout << "Items:" << endl;
    for (const auto& item : items) {
    cout << "- " << item.item.getName() << " x" << item.quantity << ": $" << fixed << setprecision(2) << item.item.getPrice() << endl;
    }
    cout << "Total: $" << fixed << setprecision(2) << totalAmount << endl;
    cout << "Thank you for dining with us!" << endl;
}                   
DriveThruOrder::DriveThruOrder(int id) : Order(id) {}
void DriveThruOrder::printReceipt() const {
    cout << "Drive-Thru Order Receipt" << endl;
    cout << "Order ID: " << orderID << endl;
    // print time
    // reuse the same formatting lambdas as above
    cout << "Order Time: " << DateTimeFormatter::formatLocalTime(orderTime) << endl;
    cout << "Items:" << endl;
    for (const auto& item : items) {
    cout << "- " << item.item.getName() << " x" << item.quantity << ": $" << fixed << setprecision(2) << item.item.getPrice() << endl;
    }
    cout << "Total: $" << fixed << setprecision(2) << totalAmount << endl;
    cout << "Thank you for your order!" << endl;
}                   
TakeOutOrder::TakeOutOrder(int id) : Order(id) {
}
void TakeOutOrder::printReceipt() const {
    cout << "Take-Out Order Receipt" << endl;
    cout << "Order ID: " << orderID << endl;
    cout << "Order Time: " << DateTimeFormatter::formatLocalTime(orderTime) << endl;
    cout << "Items: " << endl;
    for (const auto& item : items) {
    cout << "- " << item.item.getName() << " x" << item.quantity << ": $" << fixed << setprecision(2) << item.item.getPrice() << endl;
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
    cout << "Order Time: " << DateTimeFormatter::formatLocalTime(orderTime) << endl;
    cout << "Platform: " << platformName << endl;
    cout << "Items:" << endl;
    for (const auto& item : items) {
        cout << "- " << item.item.getName() << " x" << item.quantity << ": $" << fixed << setprecision(2) << item.item.getPrice() << endl;
    }
    double baseTotal = 0.0;
    for (const auto& item : items) {
        baseTotal += item.item.getPrice() * item.quantity;
    }
    double commission = baseTotal * commissionRate;             
    cout << "Subtotal: $" << fixed << setprecision(2) << baseTotal << endl;
    cout << "Commission (" << commissionRate * 100 << "%): $" << fixed << setprecision(2) << commission << endl;
    cout << "Total: $" << fixed << setprecision(2) << totalAmount << endl;
    cout << "Thank you for your order!" << endl; 
}