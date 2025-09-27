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

How to build and run
This project can be built either with a direct g++ command (quick) or with CMake (recommended for running tests).

Quick (single-command) build using g++:

```bash
g++ -std=c++17 -Wall -Wextra *.cpp -o restaurant_app
./restaurant_app
```

CMake (recommended) — builds app and can fetch GoogleTest to run unit tests automatically:

```bash
# from project root
mkdir -p build && cd build
cmake ..
cmake --build . --parallel
./restaurant_app
```

Run unit tests (one-command):

```bash
# uses scripts/run_tests.sh which runs CMake, builds, and executes tests
./scripts/run_tests.sh
```

If you prefer to run tests manually with CMake:

```bash
mkdir -p build && cd build
cmake -DBUILD_TESTS=ON ..
cmake --build . --parallel
ctest --output-on-failure
```

Future Improvements: 
This project can be expanded with more advanced features, such as:

Adding a more sophisticated menu-driven user interface.

Implementing a persistent data storage solution (e.g., using files) to save and load restaurant data.

Including more complex financial reports, such as monthly or quarterly summaries.

Expanding employee management to include shifts, payroll, and performance tracking.

Notes about time formatting and tests

- The project now uses `DateTimeFormatter` and prints order times in 12-hour AM/PM format (e.g. "2025-09-26 09:49:23 PM").
- The receipts intentionally omit timezone offsets and relative-time suffixes by default (simple local time output).

Sample receipt output (example):

```
Dine-In Order Receipt
Order ID: 101
Order Time: 2025-09-26 09:49:23 PM
Table Number: 5
Items:
- Burger x2: $10.99
- Fries x1: $3.49
- Soda x3: $1.99
Total: $31.44
Thank you for dining with us!
```

Optional: Howard Hinnant's date/tz library

If you want IANA timezones and DST-aware formatting, build with the date/tz library and define `USE_DATE_LIB`.

Recommended via Homebrew (macOS):

```bash
# install the date library
brew install date

# then build with the library (adjust include/lib paths if Homebrew prefix differs)
g++ -std=c++17 -Wall -Wextra -DUSE_DATE_LIB -I/usr/local/include *.cpp -o restaurant_app_date -L/usr/local/lib -ldate -ltz
```

Or use the CMake path — when you run `./scripts/run_tests.sh` CMake will fetch GoogleTest automatically; to enable `USE_DATE_LIB` with CMake add `-DUSE_DATE_LIB=ON` during configuration and ensure the date library is visible to the compiler/linker.

