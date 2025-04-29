#ifndef TIMER_HPP
#define TIMER_HPP

#include <string>

/**
 * @class Timer
 * @brief A simple countdown timer utility class.
 * 
 * Provides functionality to convert, format, and start timers using time in minutes.
 * Useful for applications like Pomodoro timers or task tracking systems.
 */
class Timer {
public:

    Timer();

    /**
     * @brief Converts a time string in minutes to seconds.
     * @param timeInMinutes A string representing time in minutes (e.g., "25").
     * @return Time in seconds as an integer.
     */
    int convertTimeInSeconds(const std::string timeInMinutes);

    /**
     * @brief Formats a time value (in seconds) as a MM:SS string.
     * @param time Reference to time in seconds.
     * @return A formatted string (e.g., "05:00").
     */
    std::string formatTime(int& time);

    /**
     * @brief Starts the countdown timer based on a given time in minutes.
     * @param timeInMinutes A string representing time in minutes.
     */
    void startTimer(const std::string& timeInMinutes);

private:
    int time; ///< Stores the time in seconds.
};

#endif // TIMER_HPP