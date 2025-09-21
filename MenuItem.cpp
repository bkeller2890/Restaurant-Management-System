#include "MenuItem.h"
#include <iostream> 
#include <iomanip>
#include <string>

using namespace std;

/*

MenuItem class: 
    - name 
    - description 
    - price 
    - cost 

    + getCost() : double
    + setPrice(newPrice) : void
    + getProfitMargin() : double 



*/

//TODO: Implement methods to handle item categories
//TODO: Implement methods to handle item availability
//TODO: Implement methods to handle item customization options
//TODO: Implement methods to handle item ratings and reviews
//TODO: Implement methods to handle item images or media
//TODO: Implement methods to handle item nutritional information
//TODO: Implement methods to handle item allergens
//TODO: Implement methods to handle item preparation time



MenuItem::MenuItem(string name, string description, double price, double cost){
    this->name = name; 
    this->price = price; 
    this->description = description; 
    this->cost = cost; 
}; 

string MenuItem::getName() const {
    return this->name; 
};

string MenuItem::getDescription() const{
    return this->description; 
};

double MenuItem::getPrice() const {
    return this->price; 
};

double MenuItem::getCost() const {
    return this->cost; 
};

void MenuItem::setPrice(double newPrice){
    this->price = newPrice; 
};


void MenuItem::getProfitMargin(){
    double profitMargin = ((this->price - this->cost) / this->price) * 100; 
    cout << fixed << setprecision(2) << "Profit Margin: " << profitMargin << "%" << endl; 
};
