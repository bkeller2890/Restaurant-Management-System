#ifndef ORDER_H
#define ORDER_H 

#include <string>
#include <vector>
#include <utility> 
#include "MenuItem.h"

using namespace std;

struct OrderItem {
    MenuItem item;
    int quantity;
}; 

class Order {
    protected:
        int orderID;
    vector<OrderItem> items;
        string orderTime; // Could be a timestamp or formatted string
        double totalAmount;
    public:
        Order(int id); 
        virtual ~Order();
    void addItem(const MenuItem& item, int quantity = 1);
        virtual double calculateTotal(); 
        virtual void printReceipt() const = 0;
};

class DineInOrder : public Order {
    private:
        int tableNumber;
    public:
        DineInOrder(int id, int tableNum);
        void printReceipt() const override;
};

class DriveThruOrder : public Order {
    public:
        DriveThruOrder(int id);
        void printReceipt() const override;
};

class TakeOutOrder : public Order {
    public:
        TakeOutOrder(int id);
        void printReceipt() const override;
};

class DeliveryOrder : public Order {
    private:
        string platformName;
        double commissionRate; // e.g., 0.2 for 20%
    public:
        DeliveryOrder(int id, string platform, double commission);
        double calculateTotal() override;
        void printReceipt() const override;
};

#endif // ORDER_H