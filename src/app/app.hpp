// app.hpp
#pragma once

#include <string> // C++ librarie for managing strings objects.
#include <vector> // C++ librarie for managing dynamic Arrays.

#include "../../libs/include/miniaudio.h" // Small C librarie for managing the audio system.

/**
 * @brief App class to execute and manage the main functionalities of the program.
 * 
 *  This class handles all the functions of the program. The main function is to run the project, 
 *  but it also contains other important functions to initialize the app in your terminal 
 *  environment.
 */
class App {
public:

    /**
     *  @brief Construct a new App object
     * 
     *  Creates an instance of the App class.
     */
    App();

    /**
    *  @brief Runs the main application loop, handling the menu, user choices, tasks, and timer.
    *
    *  Activates the main application loop, displays the menu, and prompts the user to select an option.
    *  If the user's choice is valid, the system will execute the corresponding functionality.
    *  After completion, the loop restarts and waits for the next input.
    */
    void run();

    /**
    *  @brief This function displays a menu.
    * 
    *  The sole purpose of this function is to present the menu.
    *  It does not perform any additional operations or interactions.
    */
    void printMenu();

    /**
    *  @brief Gets user input using standard input (std::cin).
    * 
    *  This function retrieves input directly from the user through the console.
    */
    void getUserInput();

    /**
    * @brief Validates user input.
    * 
    * This function checks the user-provided input to ensure it meets the required criteria.
    * It should handle cases of invalid or unexpected input and provide feedback or corrections 
    * accordingly.
    */
    void validateInput();

    /**
    * @brief Detects and retrieves key press events.
    * 
    * This function captures a key press from the user, allowing further processing
    * or actions based on the input. Ensure appropriate handling of key press events 
    * for different scenarios or inputs.
    */
    void getKeyPress();

    /**
    * @brief Clears the console screen.
    * 
    * This function resets the console display by removing any previous output.
    * It is typically used to enhance user experience by starting with a clean slate.
    * Implementation may vary depending on the operating system 
    * (e.g., using system("cls") for Windows or system("clear") for Unix-based systems).
    */
    void clearScreen();

    /**
    * @brief Plays a sound file for a specified duration.
    * 
    * @param path The file path of the sound to be played.
    * @param seconds The duration (in seconds) for which the sound will be played.
    * 
    * Ensure the provided file path is valid and accessible. 
    * The implementation may depend on external libraries or platform-specific audio 
    * APIs for handling sound playback.
    */
    void playSound(const std::string& path, int seconds);
    
   /**
   * @brief Saves the current task to an in-memory container.
   * 
   * This function adds the current task to a std::vector that acts as an 
   * in-memory storage for tasks. The vector ensures that tasks are stored 
   * sequentially and can be accessed or modified later. 
   */
    void saveTask();

    /**
    * @brief Displays the list of tasks stored in memory.
    * 
    * This function iterates through the `tasks` vector and prints each task
    * to the console, providing a clear view of all tasks entered by the user.
    * If the task list is empty, the function informs the user accordingly to
    * ensure clarity and prevent confusion. This functionality helps the user
    * review their tasks efficiently.
    */
    void showTaskList();

   /**
   * @brief Starts a timer to track elapsed time.
   * 
   * This function initializes and begins a timer, which can be used to measure
   * a specific duration or track how much time has passed. The implementation
   * could involve pausing program execution for a specified time or triggering
   * actions after the timer completes.
   */
    void startTimer();

    /**
    * @brief Terminates the program and exits gracefully.
    * 
    * Ensures a smooth and user-friendly shutdown process for the application.
    */
    void exit();

    /**
    * @brief Checks if a file exists at the specified path.
    * 
    * @param path The file path to be checked.
    * @return true If the file exists at the given path.
    * @return false If the file does not exist at the given path.
    * 
    * This function ensures that the specified file path is valid and accessible.
    * Consider handling potential exceptions or errors based on the operating system 
    * and file system permissions.
    */
    bool fileExists(const std::string& path);

private:

    /**
    * @brief Indicates the state of a loop.
    * 
    * The `loopState` variable is used to control the execution flow of a loop.
    * Set to `true` by default, it can be toggled to terminate the loop when needed.
    */
    bool loopState = true;

    /**
    * @brief Stores user input.
    * 
    * The `input` variable holds user-provided data, typically obtained through console input 
    * or other input mechanisms. Ensure proper validation or processing of the data when utilized.
    */
    std::string input;

    /**
    * @brief Maintains a list of tasks.
    * 
    * The `tasks` vector contains a collection of strings representing tasks.
    * It supports operations such as adding, removing, and iterating over tasks.
    * Useful for applications requiring task management or organization.
    */
    std::vector<std::string> tasks;
};