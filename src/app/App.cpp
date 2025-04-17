#include "app.hpp"

#include <cctype>
#include <cstdio>
#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>

#include "../separators/separators.hpp"
#include "../timer/timer.hpp"
#include "../../libs/include/miniaudio.h"


App::App() = default;

void App::run() {
    clearScreen();
    while (loopState) {
        printMenu();
        getUserInput();
        validateInput();
        getKeyPress();
        clearScreen();
    }
}

void App::printMenu() {
    std::cout << separator_bar << std::endl;
    std::cout << tab_space << tab_space << "POMODORO TIMER" << std::endl;
    std::cout << line;

    std::cout << tab_space << "『     Save Task      』" << std::endl;
    std::cout << tab_space << "『     Task List      』" << std::endl;
    std::cout << tab_space << "『    Start Timer     』" << std::endl;
    std::cout << tab_space << "『 Set Timer Duration 』" << std::endl;
    std::cout << tab_space << "『    Delete Task     』" << std::endl;
    std::cout << tab_space << "『        Exit        』" << std::endl;
    std::cout << line;

    std::cout << separator_footer << std::endl;
}

void App::getUserInput() {
    std::cout << "\n【 Select an option 】 :";
    std::cin >> input;
    std::transform(input.begin(), input.end(), input.begin() , ::tolower);
}

void App::validateInput() {
    if (input == "6" || input == "exit") {
        std::cout << "\n✿❯─────────────「✿」─────────────❮✿" << std::endl;
        std::cout << "✿ Thank you for using our program! ✿" << std::endl;
        std::cout << "✿❯─────────────「✿」─────────────❮✿" << std::endl;
        loopState = false;
    }

    if (input == "1" || input == "save task" || input == "save") {
        std::cout << "\n【 Task Name 】: ";
        std::string task;
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, task);
        tasks.push_back(task);
    }

    if (input == "2" || input == "task list" || input == "list") {
        int counter = 0;
        std::cout << line;
        for (std::string& task : tasks) {
            std::cout << counter << " 〘 " << task << " 〙" << std::endl; 
            counter++;
        }
    }

    if (input == "3" || input == "start" || input == "start pomoodoro") {
        Timer timer;
        std::string time = std::string("20");
        std::string relaxTime = std::string("5");
        std::cout << "\n▣ Timer Started ▣" << std::endl;
        timer.startTimer(time);
        playSound("/usr/local/share/ptimer/sound.wav", 3);

        std::cout << "\n▣ Relax Time Started ▣" << std::endl;
        timer.startTimer(relaxTime);
        playSound("/usr/local/share/ptimer/sound.wav", 3);
    }

    if (input == "4" || input == "configure" || input == "configure pomodoro"){
        std::string confTime;
        std::string relaxTime;
        std::cout << "\n【 Time 】:";
        std::cin >> confTime;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n【 Relax Time 】:";
        std::cin >> relaxTime;
        
        Timer timer;
        Timer relaxTimer;
        std::cout << "\n▣ Timer Started ▣" << std::endl;
        timer.startTimer(confTime);
        playSound("/usr/local/share/ptimer/sound.wav", 3);
        std::cout << "\n▣ Relax Time Started ▣" << std::endl;
        relaxTimer.startTimer(relaxTime);
        playSound("/usr/local/share/ptimer/sound.wav", 3);
    }

    if (input == "5" || input == "delete" || input == "delete task") {
        int counter = 0;
        int taskNumber;
        for (std::string& task : tasks) {
            std::cout << counter << " 〘 " << task << " 〙" << std::endl; 
            counter++;
        }
        std::cout << "\n【 Task Number 】(Select an option to delete:):";
        std::cin >> taskNumber;

        if (taskNumber >= 0 && taskNumber < static_cast<int>(tasks.size())) {
            std::cout << "Removing: " << tasks[taskNumber] << std::endl;
            tasks.erase(tasks.begin() + taskNumber);
        } else {
            std::cout << "Invalid index. The element does not exist." << std::endl;
        }
    }
}

void App::getKeyPress() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}

void App::clearScreen() {
    std::system("clear");
}

void App::playSound(const std::string& path, int seconds) {
    if (!fileExists(path)) {
        std::cout << "The file does not exist: " << path << std::endl;
        return;
    }

    ma_engine engine;
    if (ma_engine_init(NULL, &engine) != MA_SUCCESS) {
        std::cout << "Error initializing the audio engine.\n";
        return;
    }

    if (ma_engine_play_sound(&engine, path.c_str(), NULL) != MA_SUCCESS) {
        std::cout << "Error playing the sound.\n";
        ma_engine_uninit(&engine);
        return;
    }

    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    ma_engine_uninit(&engine);

}

bool App::fileExists(const std::string& path) {
    std::ifstream file(path);
    return file.good();
}