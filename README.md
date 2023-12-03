# Practice_LeetCode_C

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Coding Style Checks](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/codeStyleCheck.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/codeStyleCheck.yml)
[![Common Function Tests](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/commonFuncTest.yml)

## Workspace Structure

C language leetcode practice overall folder structure:

- [Basics](00_Basics/) - Prerequisites
  - [VScode_Settings_Backup](00_Basics/00_VScode_Settings_Backup) - VScode settings backup
  - [Common_Func](00_Basics/01_Common_Func/) - Common c function modules
  - [Clean_Exe](00_Basics/02_Clean_Exe/) - Executables to clean all .exe files
- [Programming_Topics](Programming_Topics/) - Programming topics ([代码随想录系列](https://programmercarl.com/) / [labuladong 的算法小抄系列](https://labuladong.github.io/algo/home/))
- [Real_World_Problem](02_Real_World_Problem/) - Real world problems
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
> - Coding Style Checks: [codeStyleCheck.yml](.github/workflows/codeStyleCheck.yml).
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
