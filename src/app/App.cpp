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
    std::cout << tab_space << "『 Configure Pomodoro 』" << std::endl;
    std::cout << tab_space << "『    Delete Task     』" << std::endl;
    std::cout << tab_space << "『        Exit        』" << std::endl;
    std::cout << line;

    std::cout << separator_footer << std::endl;
}

void App::getUserInput() {
    std::cout << "\n【 Select a option 】 :";
    std::cin >> input;
    std::transform(input.begin(), input.end(), input.begin() , ::tolower);
}

void App::validateInput() {
    if (input == "6" || input == "exit") {
        std::cout << "\n✿❯─────────「✿」───────❮✿" << std::endl;
        std::cout << "✿ Gracias Por Elegirnos ✿" << std::endl;
        std::cout << "✿❯─────────「✿」───────❮✿" << std::endl;
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
        std::cout << "\n▣ Pomodoro Started ▣" << std::endl;
        timer.startTimer(time);
        playSound("../assets/sound.wav", 3);

        std::cout << "\n▣ Relax Time Started ▣" << std::endl;
        timer.startTimer(relaxTime);
        playSound("../assets/sound.wav", 3);
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
        std::cout << "\n▣ Pomodoro Started ▣" << std::endl;
        timer.startTimer(confTime);
        playSound("../assets/sound.wav", 3);
        std::cout << "\n▣ Relax Time Started ▣" << std::endl;
        relaxTimer.startTimer(relaxTime);
        playSound("../assets/sound.wav", 3);
    }

    if (input == "5" || input == "delete" || input == "delete task") {
        int counter = 0;
        int taskNumber;
        for (std::string& task : tasks) {
            std::cout << counter << " 〘 " << task << " 〙" << std::endl; 
            counter++;
        }
        std::cout << "\n【 Task Number 】(select a option to delete):";
        std::cin >> taskNumber;

        if (taskNumber >= 0 && taskNumber < static_cast<int>(tasks.size())) {
            std::cout << "Removing: " << tasks[taskNumber] << std::endl;
            tasks.erase(tasks.begin() + taskNumber);
        } else {
            std::cout << "inválid index. the element not exists." << std::endl;
        }
    }

}

void App::getKeyPress() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << "\nPresione Enter para continuar...";
    std::cin.get();
}

void App::clearScreen() {
    std::system("clear");
}

void App::playSound(const std::string& path, int seconds) {
    if (!fileExists(path)) {
        std::cout << "El archivo no existe: " << path << std::endl;
        return;
    }

    ma_engine engine;
    if (ma_engine_init(NULL, &engine) != MA_SUCCESS) {
        std::cout << "Error al inicializar el motor de audio.\n";
        return;
    }

    if (ma_engine_play_sound(&engine, path.c_str(), NULL) != MA_SUCCESS) {
        std::cout << "Error al reproducir el sonido.\n";
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