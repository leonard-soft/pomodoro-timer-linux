#include "timer.hpp"

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <iomanip>


Timer::Timer() = default;

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

std::string Timer::formatTime(int& time) {
    int minutes = time / 60;
    int seconds = time % 60;
    std::ostringstream ostringStream;
    ostringStream << std::setfill('0') << std::setw(2) << minutes << ":"
       << std::setfill('0') << std::setw(2) << seconds;
    return ostringStream.str();
}

void Timer::startTimer(const std::string& timeInMinutes) {
    int remainingTime = convertTimeInSeconds(timeInMinutes);
    while (remainingTime > 0) {
        std::cout << "remaining time: " << formatTime(remainingTime) << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        remainingTime--;
    }
    std::cout << "Time's up!" << std::endl;
}
