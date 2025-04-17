#pragma once

#include <string>
#include <vector>

#include "../../libs/include/miniaudio.h"

class App {
private:
    bool loopState = true;
    std::string input;
    std::vector<std::string> tasks;
    
public:
    App();
    void run();
    void printMenu();
    void getUserInput();
    void validateInput();
    void getKeyPress();
    void clearScreen();
    void playSound(const std::string& path, int seconds);

    bool fileExists(const std::string& path);
};