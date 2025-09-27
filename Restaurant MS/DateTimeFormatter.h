#ifndef DATE_TIME_FORMATTER_H
#define DATE_TIME_FORMATTER_H

#include <string>
#include <chrono>

// Conditional inclusion for the external date library
#ifdef USE_DATE_LIB
// Note: You would need to ensure the path to the library is correct
#include "date/tz.h" 
#endif

class DateTimeFormatter {
private:
    // Alias for convenience
    using system_clock = std::chrono::system_clock;
    
    // Helper function to safely get tm struct (implementation varies by platform)
    static std::tm getLocalTm(const system_clock::time_point& tp);

public:
    /**
     * @brief Formats a system_clock::time_point into a detailed string.
     * * This format includes the local date, time, and optional timezone information.
     * The implementation differs based on whether USE_DATE_LIB is defined.
     *
     * @param tp The time point to format.
     * @param offsetSeconds The time zone offset from UTC in seconds.
     * @param tzName The name of the time zone (e.g., "EDT", "PST").
     * @return Formatted string (e.g., "2024-01-01 12:30:00 +01:00 (CET)").
     */
    static std::string formatTimePoint(
        const system_clock::time_point& tp, 
        int offsetSeconds, 
        const std::string& tzName
    );

    /**
     * @brief Generates a simple relative time string.
     * * @param tp The historical time point to compare against 'now'.
     * @return Relative time string (e.g., "5 minutes ago", "2 days ago").
     */
    static std::string relativeTimeString(const system_clock::time_point& tp);

    /**
     * @brief Simple formatter that returns local time using a 12-hour clock.
     * * @param tp The time point to format.
     * @return Local time string (e.g., "2024-01-01 12:30:00 PM").
     */
    static std::string formatLocalTime(const system_clock::time_point& tp);
};

#endif // DATE_TIME_FORMATTER_H
