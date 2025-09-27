#include <cassert>
#include <iostream>
#include <chrono>
#include "Order.h"
#include "DateTimeFormatter.h"

using namespace std;
using namespace std::chrono;

int main() {
    // Test relativeTimeString small differences
    auto now = system_clock::now();
    auto fiveSecondsAgo = now - seconds(5);
    auto oneMinuteAgo = now - seconds(75);
    auto threeHoursAgo = now - seconds(3*3600 + 30);

    // Basic checks using DateTimeFormatter
    string s1 = DateTimeFormatter::relativeTimeString(fiveSecondsAgo);
    string s2 = DateTimeFormatter::relativeTimeString(oneMinuteAgo);
    string s3 = DateTimeFormatter::relativeTimeString(threeHoursAgo);
    // Ensure strings are non-empty and contain expected units
    assert(!s1.empty());
    assert(s1.find("seconds") != string::npos || s1.find("second") != string::npos);
    assert(!s2.empty());
    assert(s2.find("minutes") != string::npos || s2.find("minute") != string::npos || s2.find("seconds") != string::npos);
    assert(!s3.empty());
    assert(s3.find("hours") != string::npos || s3.find("hour") != string::npos || s3.find("days") != string::npos);

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
