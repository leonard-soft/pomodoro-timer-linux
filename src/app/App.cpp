// App.cpp
#include "app.hpp" // App header implementation.

#include <cctype>  // C++ librarie for managing character classification and conversion.
#include <cstdio>  // C++ librarie for managing input/output operations at the C level.
#include <ios>     // C++ librarie for managing input/output stream formatting and flags.
#include <iostream> // C++ librarie for managing input/output stream operations.
#include <limits>  // C++ librarie for managing numeric limits and characteristics.
#include <ostream> // C++ librarie for managing output stream operations.
#include <cstdlib> // C++ librarie for utilities for memory, random numbers, and environment.
#include <algorithm> // C++ librerie for algorithms like sorting and searching.
#include <string> // C++ librarie for string manipulation utilities.
#include <fstream> // C++ librarie for file input/output operations
#include <thread> // C++ librarie for multithreading support
#include <chrono> // C++ librarie for time handling utilities

#include "../separators/separators.hpp" // Header for separator-related utilities
#include "../timer/timer.hpp" // Header for timer functionalities.
#include "../../libs/include/miniaudio.h" // Library for audio processing.

/**
 * @brief Default constructor for the App class.
 * 
 * Initializes an App object with default settings or values.
 */
App::App() = default; 

/**
 * @brief Executes the main application loop.
 * 
 * Continuously runs the application while the loopState is true.
 * Handles screen clearing, menu display, user input, validation, and key press detection.
 */
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

/**
 * @brief Displays the Pomodoro Timer menu.
 * 
 * Prints a menu with options for saving tasks, viewing the task list, starting the timer,
 * setting the timer duration, deleting tasks, and exiting the application.
 */
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

/**
 * @brief Retrieves and processes user input.
 * 
 * Prompts the user to select an option and captures the input via standard input (std::cin).
 * The input is transformed to lowercase for uniform handling and comparison purposes.
 */
void App::getUserInput() {
    std::cout << "\n【 Select an option 】 :";
    std::cin >> input;
    std::transform(input.begin(), input.end(), input.begin() , ::tolower);
}

/**
 * @brief 
 * 
 */
void App::validateInput() {
    if (input == "6" || input == "exit") {
        exit();
    }

    if (input == "1" || input == "save task" || input == "save") {
        saveTask();
    }

    if (input == "2" || input == "task list" || input == "list") {
        showTaskList();
    }

    if (input == "3" || input == "start" || input == "start pomoodoro") {
       startTimer();
    }

    if (input == "4" || input == "configure" || input == "configure pomodoro"){
        setTime();
    }

    if (input == "5" || input == "delete" || input == "delete task") {
        int counter = 0;
        int taskNumber;
        for (std::string& task : tasks) {
            std::cout << counter << " 〘 " << task << " 〙" << std::endl; 
            counter++;
        }
        std::cout << "\n【 Task Number 】(Select an option to delete):";
        std::cin >> taskNumber;

        if (taskNumber >= 0 && taskNumber < static_cast<int>(tasks.size())) {
            std::cout << "Removing: " << tasks[taskNumber] << std::endl;
            tasks.erase(tasks.begin() + taskNumber);
        } else {
            std::cout << "Invalid index. The element does not exist." << std::endl;
        }
    }
}

/**
 * @brief Waits for the user to press Enter to proceed.
 * 
 * This function clears the input buffer to ensure there are no leftover 
 * characters from previous input operations. 
 * @return void This function does not return any value.
 */
void App::getKeyPress() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}

/**
 * @brief Clears the terminal screen.
 * 
 * This function executes a system command to clear the screen, making the 
 * console appear empty. It uses the "clear" command, which is standard on Unix-based systems. 
 * @return void This function does not return any value.
 */
void App::clearScreen() {
    std::system("clear");
}

/**
 * @brief Plays a sound file for a specified duration.
 * 
 * This function checks if the given sound file exists and, if so, initializes
 * an audio engine to play the sound. It allows the playback to continue for
 * a specified number of seconds before stopping the audio engine. 
 * Error handling is included to ensure smooth operation in cases 
 * where the file does not exist or the audio engine fails.
 * 
 * @param path A string representing the path to the sound file to be played.
 * @param seconds An integer specifying the duration in seconds for the sound playback.
 * @return void This function does not return any value.
 */
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

/**
 * @brief Prompts the user to input a task name and saves it to an in-memory list.
 * 
 * This function allows the user to enter a task name via the console. It ensures 
 * that any leftover input in the buffer is cleared before accepting the new input. 
 * The entered task is then added to a std::vector named `tasks`, which acts as 
 * a temporary storage for tasks. This approach ensures that tasks are saved 
 * dynamically and can be retrieved or processed later.
 */
void App::saveTask() {
    std::cout << "\n【 Task Name 】: ";
    std::string task;
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, task);
    tasks.push_back(task);
}

/**
 * @brief Displays the list of tasks with numbering for easy identification.
 * 
 * This function prints each task stored in the `tasks` vector to the console, 
 * preceded by a numerical index for better organization. It iterates through 
 * the vector, ensuring each task is formatted consistently.
 */
void App::showTaskList() {
    int counter = 0;
    std::cout << line;
    for (std::string& task : tasks) {
        std::cout << counter << " 〘 " << task << " 〙" << std::endl; 
        counter++;
    }
}

/**
 * @brief Manages a work timer followed by a relaxation timer with sound notifications.
 * 
 * This function starts two timers sequentially: one for a work period and another for a
 * relaxation period. It uses the `Timer` class to manage the durations, defined as strings
 * representing seconds. Upon the completion of each timer, a sound notification is played
 * using the `playSound` function to signal the transition. 
 */
void App::startTimer() {
    Timer timer;
    std::string time = std::string("20");
    std::string relaxTime = std::string("5");
    std::cout << "\n▣ Timer Started ▣" << std::endl;
    timer.startTimer(time);
    playSound("/usr/local/share/ptimer/assets/sound.wav", 3);

    std::cout << "\n▣ Relax Time Started ▣" << std::endl;
    timer.startTimer(relaxTime);
    playSound("/usr/local/share/ptimer/assets/sound.wav", 3);
}

void App::setTime() {
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
    playSound("/usr/local/share/ptimer/assets/sound.wav", 3);
    std::cout << "\n▣ Relax Time Started ▣" << std::endl;
    relaxTimer.startTimer(relaxTime);
    playSound("/usr/local/share/ptimer/assets/sound.wav", 3);
}

/**
 * @brief Handles program termination gracefully.
 * 
 * Displays a farewell message and decorative separators to enhance user experience.
 * Sets the loop state to false, effectively stopping the application loop and exiting the program.
 */
void App::exit() {
    std::cout << "\n✿❯─────────────「✿」─────────────❮✿" << std::endl;
    std::cout << "✿ Thank you for using our program! ✿" << std::endl;
    std::cout << "✿❯─────────────「✿」─────────────❮✿" << std::endl;
    loopState = false;
}

/**
 * @brief Checks whether a file exists at the given path.
 * 
 * This function attempts to open the specified file using an input file stream 
 * and checks if the operation was successful. If the file can be opened, 
 * it is considered to exist; otherwise, it does not.
 * 
 * @param path A string representing the path to the file to check.
 * @return true If the file exists and can be opened successfully.
 * @return false If the file does not exist or cannot be opened.
 */
bool App::fileExists(const std::string& path) {
    std::ifstream file(path);
    return file.good();
}