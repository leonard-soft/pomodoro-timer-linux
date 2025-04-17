## 🐧 POMODORO TIMER LINUX 🐧

***description:***

A simple terminal program for managing your tasks. It includes CRUD functionalities (Create, Read, Update, Delete) to help you manage tasks efficiently. Additionally, it features a Pomodoro timer, with the option to use the default time or configure the duration according to your preferences.

![image](https://github.com/user-attachments/assets/2ba97113-fd80-4e1b-8f3d-6de86906f45e)

***prerequisites***

- a C++ compiler, either g++ or clang
- CMake for project configuration and building.

<br/>

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

***user guide***
