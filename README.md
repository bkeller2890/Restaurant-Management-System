Restaurant Management System
Project Description: 
This is a simple C++ console application designed to simulate the core financial and operational management of a restaurant. It provides a structured way to handle different business aspects, including employee data, expenses, menu items, and various types of customer orders. The system calculates and reports on key financial metrics like total revenue and profit.

Key Features: 
Employee Management: Store and retrieve employee information, including name, position, ID, and wage.

Expense Tracking: Log and calculate total expenses for different operational costs.

Menu Item Definition: Create and manage menu items with details like name, description, price, and cost.

Flexible Ordering System: Process different types of orders using an object-oriented approach with polymorphism. Supported order types include:

Dine-In Orders (with table number)

Drive-Thru Orders

Take-Out Orders

Delivery Orders (with platform and commission calculation)

Financial Reporting: The system aggregates data from all orders and expenses to calculate the total revenue and profit.

Class Structure
The project is organized into several classes, each with a specific responsibility:

MenuItem.h / MenuItem.cpp: Represents a single food or beverage item available for sale.

Employee.h / Employee.cpp: Represents a single employee with their details.

Expense.h / Expense.cpp: Represents a recorded financial expense.

Order.h / Order.cpp: An abstract base class for all order types. It provides common functionality, while its subclasses (DineInOrder, DriveThruOrder, TakeOutOrder, DeliveryOrder) handle specific logic.

Restaurant.h / Restaurant.cpp: The main aggregation class that holds and manages all other objects (employees, expenses, orders) and orchestrates the financial calculations.

How to Compile and Run: 
To compile and run this program, you will need a C++ compiler (like g++).

Compile the source files:

g++ -o main main.cpp Restaurant.cpp Order.cpp MenuItem.cpp Employee.cpp Expense.cpp

This command compiles all the .cpp files and links them into a single executable file named main.

Run the executable:

./main

Future Improvements: 
This project can be expanded with more advanced features, such as:

Adding a more sophisticated menu-driven user interface.

Implementing a persistent data storage solution (e.g., using files) to save and load restaurant data.

Including more complex financial reports, such as monthly or quarterly summaries.

Expanding employee management to include shifts, payroll, and performance tracking.

Quick build & test (recommended):

Build with warnings and C++17:

```bash
g++ -std=c++17 -Wall -Wextra *.cpp -o restaurant_app
```

Run the app:

```bash
./restaurant_app
```

Run the simple smoke test (prints a receipt):

```bash
g++ -std=c++17 -Wall -Wextra tests/time_tests.cpp *.cpp -o time_tests
./time_tests
```

Sample receipt output (example):

```
Dine-In Order Receipt
Order ID: 101
Order Time: 2025-09-26 14:32:10 +02:00 (CEST) (2 minutes ago)
Table Number: 5
Items:
- Burger x2: $10.99
- Fries x1: $3.49
- Soda x3: $1.99
Total: $35.44
Thank you for dining with us!
```

Optional: use Howard Hinnant's date/tz library for IANA timezone names

1) Install the date library (on macOS with Homebrew):

```bash
brew install date
```

2) Build with the date library enabled (add -DUSE_DATE_LIB and include path if needed):

```bash
g++ -std=c++17 -Wall -Wextra -DUSE_DATE_LIB -I/usr/local/include *.cpp -o restaurant_app_date -ltz
```

When built with the date library, receipts will include robust IANA timezone names and correct offsets (including DST handling).

