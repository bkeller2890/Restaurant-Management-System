#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
using namespace std;

class MenuItem
{
    private: 
        string name;
        string description;
        double price;
        double cost; 
    public: 
        MenuItem(string name, string description, double price, double cost);
        string getName() const; 
        string getDescription() const;
        double getPrice()const;
        double getCost() const;
        void setPrice(double newPrice);
        void getProfitMargin(); 
}; 

#endif // MENUITEM_H