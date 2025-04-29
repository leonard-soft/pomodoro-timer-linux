#include "timer.hpp"

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <iomanip>

/**
 * @brief Default constructor for Timer. Initializes time to 0.
 */
Timer::Timer() = default;

/**
 * @brief Converts a time string to total seconds.
 * 
 * Accepts input in two formats:
 * - "MM" → returns minutes * 60
 * - "MM:SS" → returns (minutes * 60) + seconds
 * 
 * @param timeInMinutes A string representing time (e.g., "25" or "5:30").
 * @return Time in seconds.
 */
int Timer::convertTimeInSeconds(const std::string timeInMinutes) {
    int minutes = 0, seconds = 0;
    char separator;

    std::stringstream stringStream(timeInMinutes);
    if (stringStream >> minutes >> separator >> seconds) {
        if (separator == ':') {
            return minutes * 60 + seconds;
        }
    } else if (stringStream.clear(), stringStream.seekg(0), stringStream >> minutes) {
        return minutes * 60;
    }
    return 0;
}

/**
 * @brief Formats seconds into MM:SS format.
 * 
 * @param time Time in seconds (passed by reference).
 * @return A string formatted as "MM:SS".
 */
std::string Timer::formatTime(int& time) {
    int minutes = time / 60;
    int seconds = time % 60;
    std::ostringstream ostringStream;
    ostringStream << std::setfill('0') << std::setw(2) << minutes << ":"
       << std::setfill('0') << std::setw(2) << seconds;
    return ostringStream.str();
}

/**
 * @brief Starts a countdown timer using the given time string.
 * 
 * Prints remaining time every second until it reaches 0.
 * 
 * @param timeInMinutes Time string in "MM" or "MM:SS" format.
 */
void Timer::startTimer(const std::string& timeInMinutes) {
    int remainingTime = convertTimeInSeconds(timeInMinutes);
    while (remainingTime > 0) {
        std::cout << "remaining time: " << formatTime(remainingTime) << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        remainingTime--;
    }
    std::cout << "Time's up!" << std::endl;
}
