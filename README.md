# Practice_LeetCode_C

| Topics | Badges |
|:-:|:-|
| License | [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) |
| Common Functions | [![Common Function Lints](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncLint.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncLint.yml) [![Common Function Tests](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml) |
| CodeQL | [![CodeQL](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/github-code-scanning/codeql/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/github-code-scanning/codeql) |

## Workspace Structure

C language leetcode practice overall folder structure:

- [Prerequisite](./00_Prerequisite/) - This folder contains the basic configuration files and common function modules before getting started with the local leetcode practice.
  - [VSCode_Settings](./00_Prerequisite/00_VSCode_Settings/) - VSCode settings
  - [Clean_Exe](./00_Prerequisite/01_Clean_Exe/) - Scripts to clean all .exe files
- [Common_Functions](./01_Common_Functions/) - Common C functions used by different programming topics.
  - [cfg](./01_Common_Functions/cfg/) - Common function configuration files.
  - [inc](./01_Common_Functions/inc/) - Common function header files.
  - [src](./01_Common_Functions/src/) - Common function source files.
  - [test](./01_Common_Functions/test/) - Common function test files.
- [Programming_Topics](./02_Programming_Topics/) - ([Programming Carl Series](https://programmercarl.com/) / [Labuladong's Algorithm Cheat Sheet](https://labuladong.github.io/algo/home/)) - This folder contains the leetcode practice questions organized by programming topics.
  - [Array](./02_Programming_Topics/01_Array/)
  - [Linked_List](./02_Programming_Topics/02_Linked_List/)
  - [Hash_Table](./02_Programming_Topics/03_Hash_Table/)
  - [String](./02_Programming_Topics/04_String/)
  - [Double_Pointer](./02_Programming_Topics/05_Double_Pointer/)
  - [Stack_Queue](./02_Programming_Topics/06_Stack_Queue/)
  - [Binary_Tree](./02_Programming_Topics/07_Binary_Tree/)
  - [Backtracking](./02_Programming_Topics/08_Backtracking/)
  - [Greedy](./02_Programming_Topics/09_Greedy/)
  - [Dynamic_Programming](./02_Programming_Topics/10_Dynamic_Programming/)
  - [Monotone_Stack](./02_Programming_Topics/11_Monotone_Stack/)
  - [Graph_Theory](./02_Programming_Topics/12_Graph_Theory/)
  - [Binary_Search](./02_Programming_Topics/13_Binary_Search/)
  - [Breath_First_Search](./02_Programming_Topics/14_Breath_First_Search/)
  - [Depth_First_Search](./02_Programming_Topics/15_Depth_First_Search/)
  - [Sliding_Window](./02_Programming_Topics/16_Sliding_Window/)
  - [Buy_And_Sell](./02_Programming_Topics/17_Buy_And_Sell/)
  - [House_Robber](./02_Programming_Topics/18_House_Robber/)
  - [N_Sum](./02_Programming_Topics/19_N_Sum/)
- [Misc](./03_Misc/) - This folder contains miscellaneous topics.
  - [Programming_Notes](./03_Misc/00_Programming_Notes/)
  - [Real_World_Problem](./03_Misc/01_Real_World_Problems/)
  - [Supplementary_Materials](./03_Misc/02_Supplementary_Materials/)

## Common Function Modules

To ensure code quality, all shared common code based on different programming topics will be placed in the [Common_Functions](./01_Common_Functions/) folder following these workflows:

| Workflows | Source Code |
|----------|----------|
|   [![Common Function Lints](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncLint.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncLint.yml)  |   [commonFuncLint.yml](.github/workflows/commonFuncLint.yml)   |
|   [![Common Function Tests](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml)  |   [commonFuncTest.yml](.github/workflows/commonFuncTest.yml)   |

## Code Structure

> The code structure of each question is as follows:
>
> ```txt
> .
> ├── cfg                               /* configuration folder */
> │   ├── compileCfg.h                      /* common function configuration file */
> │   └── methodCfg.h                       /* solution method configuration file */
> ├── doc                               /* documentation folder */
> │   ├── sketch.drawio                     /* drawing sketch file */
> │   └── sketch.excalidraw                 /* drawing sketch file */
> ├── inc                               /* header folder */
> │   └── solutionName.h                    /* solution header file */
> ├── src                               /* source folder */
> │   ├── solutionName_methodName01.c       /* solution method 01 source file */
> │   ├── solutionName_methodName02.c       /* solution method 02 source file */
> │   ├── ...
> │   └── solutionName_methodNameXX.c       /* solution method XX source file */
> └── main.c                            /* main.c file */
> ```
>
> **Example**: `\Practice_LeetCode_C\01_Programming_Topics\01_Array\01_binarySearch\main.c`
>
> The call hierarchy between files is as follow:
>
> ![Call Hierarchy](./03_Misc/02_Supplementary_Materials/callHierarchy.png)

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

> To execute the source code in VSCode, choose the desired `main.c` file and navigate to the following tab and options in the VSCode interface:
>
> ```txt
> Terminal -> Run Task... -> Build & Run Current File
> ```
>
> or simply press
>
> ```txt
> Ctrl + Shift + B
> ```
>
> Source code: [tasks.json](.vscode/tasks.json) and [python build.py](.vscode/build.py).

### VSCode Extension - Code Runner

> The **`Code Runner`** vscode extension provides a convenient way to execute the `main.c` file directly.
>
> Source code: [settings.json](.vscode/settings.json).

### Build Process

> The gcc compilation process is as follows:
>
> 1. Search for the header in `/01_Common_Functions/inc/commonDef/` and `/01_Common_Functions/inc/` folders.
>
> 2. Search for the header in `${fileDirname}/cfg/` and `${fileDirname}/inc/` folder.
>
> 3. Search and compile all the `/01_Common_Functions/src/*.c` and `${fileDirname}/src/*.c` with `${fileDirname}/main.c` as the entry point.
>
> 4. Generate the executable file in `${fileDirname}/` folder with name `main.exe`.
>
> Source code: [python build.py](.vscode/build.py) and [settings.json](.vscode/settings.json).

## Debug Code

> To facilitate source code debugging in VSCode, select the `main.c` file that you wish to run.
> First, build and run the source code as described in the previous section.
> Then, click the following button in VSCode:
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

> To ensure a clean development environment, it is important to remove unnecessary executable files.
> The following steps can be used to clean all .exe files:
>
> First, open the terminal by pressing
>
> ```txt
> ctrl + ~
> ```
>
> then run
>
> ```txt
> .\00_Basics\02_Clean_Exe\killexe.bat        /* windows system */
> ./00_Basics/02_Clean_Exe/killexe.sh         /* linux system */
> ```
>
> Source code: [killExes.bat](./00_Prerequisite/01_Clean_Exe/killExes.bat) and [killExes.sh](./00_Prerequisite/01_Clean_Exe/killExes.sh).
