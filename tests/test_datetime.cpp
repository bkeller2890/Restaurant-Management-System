// GoogleTest-based unit tests
#include <gtest/gtest.h>

#include "DateTimeFormatter.h"
#include "Order.h"
#include "MenuItem.h"

using namespace std;
using namespace std::chrono;

TEST(DateTimeFormatterTests, FormatLocalTimeProducesAMPM) {
    auto now = system_clock::now();
    string s = DateTimeFormatter::formatLocalTime(now);
    EXPECT_FALSE(s.empty());
    // Expect AM or PM in the string (12-hour format)
    EXPECT_TRUE(s.find("AM") != string::npos || s.find("PM") != string::npos);
}

TEST(DateTimeFormatterTests, RelativeTimeStringUnits) {
    auto now = system_clock::now();
    auto fiveSecondsAgo = now - seconds(5);
    auto oneMinuteAgo = now - seconds(75);
    auto threeHoursAgo = now - hours(3) - minutes(30);

    auto s1 = DateTimeFormatter::relativeTimeString(fiveSecondsAgo);
    auto s2 = DateTimeFormatter::relativeTimeString(oneMinuteAgo);
    auto s3 = DateTimeFormatter::relativeTimeString(threeHoursAgo);

    EXPECT_FALSE(s1.empty());
    EXPECT_NE(string::npos, s1.find("second"));

    EXPECT_FALSE(s2.empty());
    EXPECT_TRUE(s2.find("minute") != string::npos || s2.find("second") != string::npos);

    EXPECT_FALSE(s3.empty());
    EXPECT_TRUE(s3.find("hour") != string::npos || s3.find("day") != string::npos);
}

TEST(OrderTests, CalculateTotalWithQuantities) {
    DineInOrder order(500, 1);
    MenuItem burger("Burger", "Gourmet", 10.0, 5.0);
    MenuItem fries("Fries", "Side", 3.0, 1.0);

    order.addItem(burger, 2); // 20
    order.addItem(fries, 3);  // 9
    double total = order.calculateTotal();
    EXPECT_NEAR(total, 29.0, 1e-3);
}
