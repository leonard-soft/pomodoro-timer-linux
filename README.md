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
【 Select an option 】 : 1 // If your choice is 1

【 Task Name 】: update the repository

Press Enter to continue...
```
![image](https://github.com/user-attachments/assets/d9576b59-b9e9-4092-bdd5-0530dc077ef9)

<br/>

```bash 
  【 Select an option 】 : 2 // If your choice is 2

  0 〘 update the repository 〙
  1 〘 other task 〙

  Press Enter to continue...
```
![image](https://github.com/user-attachments/assets/27356ee3-5ddd-4470-9084-b5a1d0763053)

<br/>

```bash 
【 Select an option 】 : 3 // If your choice is 3

▣ Timer Started ▣
remaining time: 20:00
remaining time: 19:59
remaining time: 19:58
remaining time: 19:57
remaining time: 19:56
...
```
![image](https://github.com/user-attachments/assets/1e0e0949-c8e6-479a-843f-e541251c5a1c)

<br/>

```bash
  【 Select an option 】 : 4 // If your choice is 4

【 Time 】:1

【 Relax Time 】:1

▣ Timer Started ▣
remaining time: 01:00
remaining time: 00:59
remaining time: 00:58
remaining time: 00:57
...
```
![image](https://github.com/user-attachments/assets/e2b55a21-cfca-446c-a781-9a7afdcd2726)

<br/>

```bash
【 Select an option 】 : 5 // If your choice is five
0 〘 task 〙
1 〘 another task  〙

【 Task Number 】(Select an option to delete:): 1

```
![image](https://github.com/user-attachments/assets/8d07683e-4dd3-48b9-a492-20a7cd085b50)


📝 Note: Before deleting a task, make sure there are tasks available in the list.
If the list is empty, there’s nothing to delete!

<br/>

```bash
【 Select an option 】 : 6 // If your choice is 6

✿❯─────────────「✿」─────────────❮✿
✿ Thank you for using our program! ✿
✿❯─────────────「✿」─────────────❮✿

Press Enter to continue...

```
![image](https://github.com/user-attachments/assets/4c97b103-2fc0-47f8-a8e5-965f7187fade)


If you select 6, the program will exit gracefully, thanking you for using it.

------

***About the Author***

Developed by Leonard Soft — passionate about creating efficient and simple open-source tools for GNU/Linux environments.
If you like this project or have suggestions, feel free to open an issue or fork it!

