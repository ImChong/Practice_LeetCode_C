# Practice_LeetCode_C

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Common Function Lints](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncLint.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncLint.yml)
[![Common Function Tests](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml)
[![CodeQL](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/github-code-scanning/codeql/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/github-code-scanning/codeql)

## Workspace Structure

C language leetcode practice overall folder structure:

- [Basics](./00_Basics/) - This folder contains the basic configuration files and common function modules before getting started with the local leetcode practice.
  - [VScode_Settings_Backup](./00_Basics/00_VScode_Settings_Backup) - VSCode settings backup
  - [Common_Func](./00_Basics/01_Common_Func/) - Common c function modules
  - [Clean_Exe](./00_Basics/02_Clean_Exe/) - Executables to clean all .exe files
- [Programming_Topics](./01_Programming_Topics/) - ([Programming Carl Series](https://programmercarl.com/) / [Labuladong's Algorithm Cheat Sheet](https://labuladong.github.io/algo/home/)) - This folder contains the leetcode practice questions by programming topics.
  - [Array](./01_Programming_Topics/01_Array/) - Array
  - [Linked_List](./01_Programming_Topics/02_Linked_List/) - Linked list
  - [Hash_Table](./01_Programming_Topics/03_Hash_Table/) - Hash table
  - [String](./01_Programming_Topics/04_String/) - String
  - [Double_Pointer](./01_Programming_Topics/05_Double_Pointer/) - Double pointer
  - [Stack_Queue](./01_Programming_Topics/06_Stack_Queue/) - Stack & Queue
  - [Binary_Tree](./01_Programming_Topics/07_Binary_Tree/) - Binary tree
  - [Backtracking](./01_Programming_Topics/08_Backtracking/) - Backtracking
  - [Greedy](./01_Programming_Topics/09_Greedy/) - Greedy
  - [Dynamic_Programming](./01_Programming_Topics/10_Dynamic_Programming/) - Dynamic programming
  - [Monotone_Stack](./01_Programming_Topics/11_Monotone_Stack/) - Monotone stack
  - [Graph_Theory](./01_Programming_Topics/12_Graph_Theory/) - Graph theory
  - [Binary_Search](./01_Programming_Topics/13_Binary_Search/) - Binary search
  - [Breath_First_Search](./01_Programming_Topics/14_Breath_First_Search/) - Breath first search
  - [Depth_First_Search](./01_Programming_Topics/15_Depth_First_Search/) - Depth first search
  - [Sliding_Window](./01_Programming_Topics/16_Sliding_Window/) - Sliding window
  - [Buy_And_Sell](./01_Programming_Topics/17_Buy_And_Sell/) - Buy and sell
  - [House_Robber](./01_Programming_Topics/18_House_Robber/) - House robber
  - [N_Sum](./01_Programming_Topics/19_N_Sum/) - N sum
- [Misc](./02_Misc/) - This folder contains miscellaneous topics.
  - [Programming_Notes](./02_Misc/00_Programming_Notes/) - Programming notes
  - [Real_World_Problem](./02_Misc/01_Real_World_Problems/) - Real world problems

## Common Function Modules

To ensure code quality, all shared common code based on different programming topics will be placed in the [Common_Func](00_Basics/01_Common_Func/) folder following these workflows:

| Workflows | Source Code |
|----------|----------|
|   [![Common Function Lints](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncLint.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncLint.yml)  |   [commonFuncLint.yml](.github/workflows/commonFuncLint.yml)   |
|   [![Common Function Tests](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml)  |   [commonFuncTest.yml](.github/workflows/commonFuncTest.yml)   |

## Code Structure

> If the question can be solved by only one method, the problem code structure will be as follows:
>
> ```txt
> .
> ├── cfg                                   /* configuration folder */
> │   └── compileCfg.h                          /* common function modules configuration */
> └── main.c                                /* main.c file */
> ```
>
> **Example**: `\Practice_LeetCode_C\01_Programming_Topics\01_Array\01_binarySearch\main.c`
>
> If the question can be solved by multiple methods, the problem code structure will be as follows:
>
> ```txt
> .
> ├── cfg                                   /* configuration folder */
> │   ├── compileCfg.h                          /* common function modules configuration */
> │   └── methodCfg.h                           /* method configuration */
> ├── docs                                  /* documentation folder */
> │   ├── sketch.drawio                         /* drawing sketch file */
> │   └── sketch.excalidraw                     /* drawing sketch file */
> ├── inc                                   /* header folder */
> │   └── solutionName.h                        /* solution header file */
> ├── main.c                                /* main.c file */
> └── src                                   /* source folder */
>     ├── solutionName_methodName01.c           /* solution method 01 source file */
>     ├── solutionName_methodName02.c           /* solution method 02 source file */
>     ├── ...
>     └── solutionName_methodNameXX.c           /* solution method XX source file */
> ```
>
> **Example**: `\Practice_LeetCode_C\01_Programming_Topics\03_Hash_Table\02_intersection\main.c`
>

## Build & Run Code

### Operating Systems

> - Windows
> - Ubuntu

### Build Tool Versions

> - Python 3.12.1
> - gcc.exe (Rev7, Built by MSYS2 project) 13.1.0
> - g++.exe (Rev7, Built by MSYS2 project) 13.1.0
> - GNU gdb (GDB) 13.2

### VSCode Native - Build & Run Current File

> In order to run source code in VSCode, select the `main.c` file that wish to run. Then click the following tab and options in VSCode:
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
> Source code: [tasks.json](.vscode/tasks.json) and [python build.py](.vscode/build.py).

### VSCode Extension - Code Runner

> The `Code Runner` vscode extension can be used to run the `main.c` file directly.
>
> Source code: [settings.json](.vscode/settings.json).

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
> Source code: [launch.json](.vscode/launch.json).

## Clean all .exe files

> Open the terminal by pressing
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
>
> Source code: [killExes.bat](./00_Basics/02_Clean_Exe/killExes.bat) and [killExes.sh](./00_Basics/02_Clean_Exe/killExes.sh).
