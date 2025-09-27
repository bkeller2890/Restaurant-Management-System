// Clean, single implementation for DateTimeFormatter
#include "DateTimeFormatter.h"
#include <ctime>
#include <chrono>
#include <cmath>
#include <cstdio> // for snprintf
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// Thread-safe local tm retrieval where possible
std::tm DateTimeFormatter::getLocalTm(const system_clock::time_point& tp) {
    time_t t = system_clock::to_time_t(tp);
    std::tm result{};
#if defined(__unix__) || defined(__APPLE__)
    if (localtime_r(&t, &result) != nullptr) return result;
#elif defined(_WIN32)
    localtime_s(&result, &t);
    return result;
#endif
    // Fallback (not thread-safe)
    std::tm* p = std::localtime(&t);
    if (p) return *p;
    return result;
}

std::string DateTimeFormatter::formatTimePoint(const system_clock::time_point& tp, int offsetSeconds, const std::string& tzName) {
#ifdef USE_DATE_LIB
    try {
        auto z = date::current_zone();
        if (z) return date::format("%Y-%m-%d %H:%M:%S %z (%Z)", date::make_zoned(z, tp));
    } catch (...) {}
#endif
    std::tm tm = getLocalTm(tp);
    char buf[128];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm);
    int offs = offsetSeconds;
    int mm = (std::abs(offs) % 3600) / 60;
    char tz[16];
    snprintf(tz, sizeof(tz), "%+03d:%02d", offs / 3600, mm);
    return string(buf) + " " + tz + " (" + tzName + ")";
}

std::string DateTimeFormatter::relativeTimeString(const system_clock::time_point& tp) {
    auto now = system_clock::now();
    long long diff = duration_cast<seconds>(now - tp).count();
    if (diff < 0) return "in the future";
    if (diff < 60) return to_string(diff) + " seconds ago";
    if (diff < 3600) return to_string(diff / 60) + " minutes ago";
    if (diff < 86400) return to_string(diff / 3600) + " hours ago";
    return to_string(diff / 86400) + " days ago";
}

std::string DateTimeFormatter::formatLocalTime(const system_clock::time_point& tp) {
    std::tm tm = getLocalTm(tp);
    char buf[128];
    strftime(buf, sizeof(buf), "%Y-%m-%d %I:%M:%S %p", &tm);
    return string(buf);
}
