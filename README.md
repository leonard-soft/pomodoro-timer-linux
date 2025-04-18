## 🐧 POMODORO TIMER LINUX 🐧

***description:***

A simple terminal program for managing your tasks. It includes CRUD functionalities (Create, Read, Update, Delete) to help you manage tasks efficiently. Additionally, it features a Pomodoro timer, with the option to use the default time or configure the duration according to your preferences.

![image](https://github.com/user-attachments/assets/2ba97113-fd80-4e1b-8f3d-6de86906f45e)

***prerequisites***

- a C++ compiler, either g++ or clang
- CMake for project configuration and building.

<br/>

--------

***Installation***
```bash 
git clone https://github.com/leonard-soft/pomodoro-timer-linux.git
cd pomodoro-timer-linux
cmake -S . -B build
cd build
make
sudo make install
```

From this moment on, you can use the application, you can test it in the terminal with the command ***ptimer***, here is an example

```bash
  ptimer

// This menu will appear when you run the program.

╭━━━━━━━━━━╯☆●ʚ♡ɞ●☆╰━━━━━━━━━━╮
        POMODORO TIMER

    『     Save Task      』
    『     Task List      』
    『    Start Timer     』
    『 Set Timer Duration 』
    『    Delete Task     』
    『        Exit        』

▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂

【 Select an option 】 :
```
<br/>

-----

***user guide***

If you're using the program right now, you're probably looking for instructions on how to use it — and you're right!
This is the user guide to help you get started.

``` bash
【 Select an option 】 : 1 // if your chooise is 1

【 Task Name 】: update the repository

Press Enter to continue...
```
![image](https://github.com/user-attachments/assets/d9576b59-b9e9-4092-bdd5-0530dc077ef9)

<br/>

```bash 
  【 Select an option 】 : 2 // if your chooise is 2

  0 〘 update the repository 〙
  1 〘 other task 〙

  Press Enter to continue...
```
![image](https://github.com/user-attachments/assets/27356ee3-5ddd-4470-9084-b5a1d0763053)

------

***About the Author***

Developed by Leonard Soft — passionate about creating efficient and simple open-source tools for GNU/Linux environments.
If you like this project or have suggestions, feel free to open an issue or fork it!

