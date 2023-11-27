# Practice_LeetCode_C

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Workspace Structure

C language leetcode practice overall folder structure:

- [Basics](00_Basics/) - Prerequisites
  - [VScode_Settings_Backup](00_Basics/00_VScode_Settings_Backup) - VScode settings backup
  - [Common_Func](00_Basics/01_Common_Func/) - Common c function modules
  - [Clean_Exe](00_Basics/02_Clean_Exe/) - Executables to clean all .exe files
- [Programming_Topics](Programming_Topics/) - [代码随想录系列](https://programmercarl.com/) / [labuladong 的算法小抄系列](https://labuladong.github.io/algo/home/)
- [Real_World_Problem](02_Real_World_Problem/) - Real world problem
- [Misc](03_Misc/) - Miscellaneous
  - [Programming_Notes](03_Misc/00_Programming_Notes/) - Programming notes

## Build Tool Versions

- gcc.exe (Rev7, Built by MSYS2 project) 13.1.0
- g++.exe (Rev7, Built by MSYS2 project) 13.1.0
- GNU gdb (GDB) 13.2

## Code Structure

> If the question has multiple solutions, the code structure will be as follows:
>
> ```txt
> .
> ├── cfg                                   /* configuration folder */
> │   ├── compileCfg.h                          /* compile configuration */
> │   └── methodCfg.h                           /* method configuration */
> ├── docs                                  /* documentation folder */
> │   └── sketch.drawio                         /* drawing sketch file */
> ├── inc                                   /* header folder */
> │   └── solutionName.h                        /* solution header file */
> ├── main.c                                /* main & test source file */
> └── src                                   /* source folder */
>     ├── solutionName_methodName01.c           /* solution method 01 source file */
>     └── solutionName_methodName02.c           /* solution method 02 source file */
> ```
>
> if the question has only one solution, the code structure will be as follows:
>
> ```txt
> .
> ├── cfg                                   /* configuration folder */
> │   └── compileCfg.h                          /* compile configuration */
> └── main.c                                /* main & test source file */
> ```
>
> all the shared common code will be placed in [Common_Func](00_Basics/01_Common_Func/) folder.

## Build & Run Code

### VSCode Native - Build & Run Current File

> In order to run source code in VSCode, select the main.c file that wish to run. Then click the following button in VSCode:
>
> ```txt
> Terminal -> Run Task... -> Build & Run Current File
> ```
>
> or simply press
>
> ```txt
> Ctrl+Shift+B
> ```
>
> for the code to accomplish the above behavior please see [source code](.vscode/tasks.json) and [python gcc build code](.vscode/build.py).

### VSCode Extension - Code Runner

> for the `Code Runner` vscode extension to accomplish the above behavior please see [source code](.vscode/settings.json).

## Debug Code

> In order to debug source code in VSCode, select the .c file that wish to run.
> First Build & Run source code as the above section.
> Then click the following button in VSCode:
>
> ```txt
> Run and Debug (Ctil+Shift+D) -> (gdb) Debug Main
> ```
>
> or simply press
>
> ```txt
> F5
> ```
>
> for the code to accomplish the above behavior please see [source code](.vscode/launch.json).

## Clean all .exe files

> Open the terminal
>
> ```txt
> ctrl+~
> ```
>
> then run
>
> ```txt
> .\00_Basics\02_Clean_Exe\killexe.bat        /* windows system */
> ./00_Basics/02_Clean_Exe/killexe.sh         /* linux system */
> ```

for the code to accomplish the above behavior please see [source code](./00_Basics/02_Clean_Exe/).

## Progress

- [x] .
- [x] ├── 00_Basics
- [x] │   ├── 00_VScode_Settings_Backup
- [x] │   ├── 01_Common_Func
- [x] │   └── README.md
- [x] ├── 01_Programming_Topics
- [x] │   ├── 01_Array
- [x] │   ├── 02_Linked_List
- [x] │   ├── 03_Hash_Table
- [x] │   ├── 04_String
- [ ] │   ├── 05_Double_Pointer
- [ ] │   ├── 06_Stack_Queue
- [x] │   ├── 07_Binary_Tree
- [ ] │   ├── 08_Backtracking
- [ ] │   ├── 09_Greedy
- [ ] │   ├── 10_Dynamic_Programming
- [ ] │   ├── 11_Monotone_Stack
- [ ] │   ├── 12_Graph_Theory
- [ ] │   ├── 13_Breadth_First_Search
- [ ] │   ├── 14_Binary_Search
- [ ] │   ├── 15_Sliding_Window
- [ ] │   ├── 16_Buy_And_Sell
- [ ] │   ├── 17_House_Robber
- [ ] │   ├── 18_N_Sum
- [x] │   └── README.md
- [x] ├── 02_Real_World_Problem
- [ ] │   ├── Cross_Section_Line_Problem
- [x] │   └── README.md
- [x] ├── 03_Misc
- [x] │   ├── 00_Clean_Exe
- [x] │   ├── 01_Programming_Notes
- [x] │   └── README.md
- [x] ├── LICENSE
- [x] └── README.md
