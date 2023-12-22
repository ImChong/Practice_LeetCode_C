# Practice_LeetCode_C

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Common Function Lints](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncLint.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncLint.yml)
[![Common Function Tests](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml)
[![CodeQL](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/github-code-scanning/codeql/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/github-code-scanning/codeql)

## Workspace Structure

C language leetcode practice overall folder structure:

- [Basics](./00_Basics/) - Prerequisites
  - [VScode_Settings_Backup](./00_Basics/00_VScode_Settings_Backup) - VScode settings backup
  - [Common_Func](./00_Basics/01_Common_Func/) - Common c function modules
  - [Clean_Exe](./00_Basics/02_Clean_Exe/) - Executables to clean all .exe files
- [Programming_Topics](./01_Programming_Topics/) - Programming topics ([代码随想录系列](https://programmercarl.com/) / [labuladong 的算法小抄系列](https://labuladong.github.io/algo/home/))
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
  - [Breath_First_Search](./01_Programming_Topics/13_Breath_First_Search/) - Breath first search
  - [Binary_Search](./01_Programming_Topics/14_Binary_Search/) - Binary search
  - [Sliding_Window](./01_Programming_Topics/15_Sliding_Window/) - Sliding window
  - [Buy_And_Sell](./01_Programming_Topics/16_Buy_And_Sell/) - Buy and sell
  - [House_Robber](./01_Programming_Topics/17_House_Robber/) - House robber
  - [N_Sum](./01_Programming_Topics/18_N_Sum/) - N sum
- [Misc](./02_Misc/) - Miscellaneous
  - [Programming_Notes](./02_Misc/00_Programming_Notes/) - Programming notes
  - [Real_World_Problem](./02_Misc/01_Real_World_Problems/) - Real world problems

## Build Tool Versions

- Python 3.12.1
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
> │   ├── sketch.drawio                         /* drawing sketch file */
> │   └── sketch.excalidraw                     /* drawing sketch file */
> ├── inc                                   /* header folder */
> │   └── solutionName.h                        /* solution header file */
> ├── main.c                                /* main & test source file */
> └── src                                   /* source folder */
>     ├── solutionName_methodName01.c           /* solution method 01 source file */
>     ├── solutionName_methodName02.c           /* solution method 02 source file */
>     ├── ...
>     └── solutionName_methodNameXX.c           /* solution method XX source file */
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
> all the shared common code will be placed in [Common_Func](00_Basics/01_Common_Func/) folder. with the following workflows to ensure the quality of the code:
>
> - Common Function Lints: [commonFuncLint.yml](.github/workflows/commonFuncLint.yml)
> - Common Function Tests: [commonFuncTest.yml](.github/workflows/commonFuncTest.yml).

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
>
> for the code to accomplish the above behavior please see [source code](./00_Basics/02_Clean_Exe/).
