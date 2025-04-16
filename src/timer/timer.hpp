#ifndef TIMER_HPP
#define TIMER_HPP

#include <string>

class Timer {
private:
    int time;
public:
    Timer();
    int convertTimeInSeconds(const std::string timeInMinutes);
    std::string formatTime(int& time);
    void startTimer(const std::string& timeInMinutes);
};

#endif // TIMER_HPP