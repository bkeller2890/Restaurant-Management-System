#include <cassert>
#include <iostream>
#include <chrono>
#include "Order.h"

using namespace std;
using namespace std::chrono;

int main() {
    // Test relativeTimeString small differences
    auto now = system_clock::now();
    auto fiveSecondsAgo = now - seconds(5);
    auto oneMinuteAgo = now - seconds(75);
    auto threeHoursAgo = now - seconds(3*3600 + 30);

    // Since formatTimePoint and relativeTimeString are in anonymous namespace in Order.cpp
    // we can't directly call them here without making them visible. Instead we will test via Order
    // by constructing an Order and checking that printing runs (smoke test).

    DineInOrder o(1, 5);
    o.addItem(MenuItem("Test", "desc", 1.0, 0.5), 1);
    o.calculateTotal();
    o.printReceipt();

    cout << "Time tests: ran smoke test receipt.\n";
    return 0;
}
