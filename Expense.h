#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

using namespace std;

class Expense {
    private:
        string type;
        double amount;
        string date; // Format: YYYY-MM-DD
    public: 
        Expense(string type, double amount, string date); 
        
        string getType() const;  
        double getAmount() const; 
        string getDate() const;
        string OutputExpense() const;
        
}; 

#endif // EXPENSE_H