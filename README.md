# Practice_LeetCode_C

| Topics | Badges / URLs |
|:-:|:-|
| License | [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) |
| Code Style | [Google’s C++ style guide](https://google.github.io/styleguide/cppguide.html) ([Clang-Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html#clang-format-style-options)) |
| Common Functions | [![CommonFunctionLints](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/common_function_lint.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/common_function_lint.yml) [![CommonFunctionTests](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/common_function_test.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/common_function_test.yml) |
| Programming Topics | [![ProgrammingTopicLints](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/programming_topic_lint.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/programming_topic_lint.yml) [![ProgrammingTopicTests](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/programming_topic_test.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/programming_topic_test.yml) |
| CodeQL | [![CodeQL](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/github-code-scanning/codeql/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/github-code-scanning/codeql) |
<!-- | Code Coverage | [![codecov](https://codecov.io/gh/ImChong/Practice_LeetCode_C/branch/master/graph/badge.svg?token=ZQZQZQZQZQ)](https://codecov.io/gh/ImChong/Practice_LeetCode_C) | -->

## Workspace Structure

C language local leetcode practice overall folder structure:

- [Prerequisite](./F00_Prerequisite/) - This folder contains the basic configuration files and common function modules before getting started with the local leetcode practice.
  - [VSCode_Settings](./F00_Prerequisite/00_VSCode_Settings/) - VSCode settings
  - [Clean_Exe](./F00_Prerequisite/01_Clean_Exe/) - Scripts to clean all .exe files
- [Common_Functions](./F01_Common_Functions/) - Common C functions used by different programming topics with quality check workflows deployed.
  - [cfg](./F01_Common_Functions/cfg/) - Common function configuration file template.
  - [inc](./F01_Common_Functions/inc/) - Common function header files.
  - [src](./F01_Common_Functions/src/) - Common function source files.
  - [test](./F01_Common_Functions/test/) - Common function test files.
- [Programming_Topics](./F02_Programming_Topics/) - ([Programming Carl Series](https://programmercarl.com/) / [Labuladong's Algorithm Cheat Sheet](https://labuladong.github.io/algo/home/)) - This folder contains the leetcode practice questions organized by programming topics.
  - [Data_Structure](./F02_Programming_Topics/01_Data_Structure/)
    - [Array](./F02_Programming_Topics/01_Data_Structure/01_Array/)
    - [Linked_List](./F02_Programming_Topics/01_Data_Structure/02_Linked_List/)
    - [Hash_Table](./F02_Programming_Topics/01_Data_Structure/03_Hash_Table/)
    - [String](./F02_Programming_Topics/01_Data_Structure/04_String/)
    - [Stack_Queue](./F02_Programming_Topics/01_Data_Structure/05_Stack_Queue/)
    - [Binary_Tree](./F02_Programming_Topics/01_Data_Structure/06_Binary_Tree/)
    - [Monotone_Stack](./F02_Programming_Topics/01_Data_Structure/07_Monotone_Stack/)
    - [Graph_Theory](./F02_Programming_Topics/01_Data_Structure/08_Graph_Theory/)
  - [Algorithm](./F02_Programming_Topics/02_Algorithm/)
    - [Binary_Search](./F02_Programming_Topics/02_Algorithm/01_Binary_Search/)
    - [Double_Pointer](./F02_Programming_Topics/02_Algorithm/02_Double_Pointer/)
    - [Sliding_Windows](./F02_Programming_Topics/02_Algorithm/03_Sliding_Window/)
    - [Backtracking](./F02_Programming_Topics/02_Algorithm/04_Backtracking/)
    - [Greedy](./F02_Programming_Topics/02_Algorithm/05_Greedy/)
    - [Dynamic_Programming](./F02_Programming_Topics/02_Algorithm/06_Dynamic_Programming/)
    - [Breadth_First_Search](./F02_Programming_Topics/02_Algorithm/07_Breadth_First_Search/)
    - [Depth_First_Search](./F02_Programming_Topics/02_Algorithm/08_Depth_First_Search/)
  - [Software_Design_Pattern](./F02_Programming_Topics/03_Software_Design_Pattern/)
    - [Creational_Pattern](./F02_Programming_Topics/03_Software_Design_Pattern/01_Creational_Pattern/)
    - [Structural_Pattern](./F02_Programming_Topics/03_Software_Design_Pattern/02_Structural_Pattern/)
    - [Behavioral_Pattern](./F02_Programming_Topics/03_Software_Design_Pattern/03_Behavioral_Pattern/)
  - [Classic_LeetCode_Topics](./F02_Programming_Topics/04_Classic_LeetCode_Topics/)
    - [N_sum](./F02_Programming_Topics/04_Classic_LeetCode_Topics/01_N_sum/)
    - [Buy_Sell_Stock](./F02_Programming_Topics/04_Classic_LeetCode_Topics/02_Buy_Sell_Stock/)
    - [House_Robber](./F02_Programming_Topics/04_Classic_LeetCode_Topics/03_House_Robber/)
- [Misc](./F03_Misc/) - This folder contains miscellaneous topics.
  - [Programming_Notes](./F03_Misc/00_Programming_Notes/)
  - [Real_World_Problem](./F03_Misc/01_Real_World_Problems/)
  - [Supplementary_Materials](./F03_Misc/02_Supplementary_Materials/)

## Common Functions

> To ensure code quality, all shared common code based on different programming topics will be placed in the [Common_Functions](./F01_Common_Functions/) folder following these workflows:
>
> | Workflows | Functionality | Source Code |
> |:-:|:-:|:-:|
> | [![CommonFunctionLints](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/common_function_lint.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/common_function_lint.yml) | Code Style Check |  [commonFuncLint.yml](.github/workflows/common_functions/commonFuncLint.yml) |
> | [![CommonFunctionTests](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/common_function_test.yml/badge.svg)](https://github.com/ImChong/Practice_LeetCode_C/actions/workflows/common_function_test.yml) | Unit Test (Google Test) | [commonFuncTest.yml](.github/workflows/common_functions/commonFuncTest.yml) |

## Code Structure of Basic Building Unit

> To start getting hands on the project, the fundamental code structure of each question is as follows:
>
> ```txt
> .
> ├── cfg
> │   ├── compile_cfg.h                     /* common function configuration file */
> │   └── method_cfg.h                      /* solution method configuration file */
> ├── doc
> │   ├── sketch.drawio                     /* drawing sketch file */
> │   └── sketch.excalidraw                 /* drawing sketch file */
> ├── inc
> │   └── solution_name.h                   /* solution header file */
> ├── src
> │   ├── solution_name__method_name_01.c   /* solution method 01 source file */
> │   ├── solution_name__method_name_02.c   /* solution method 02 source file */
> │   ├── ...
> │   └── solution_name__method_name_xx.c   /* solution method XX source file */
> └── main.c                                /* entry point */
> ```
>
> The call hierarchy between files is as follow:
>
> ![Call Hierarchy](./F03_Misc/F02_Supplementary_Materials/call_hierarchy.png)
>
> The `main.c` file is the entry point of the program, which calls the solution method in the `solution_name__method_name_xx.c` file. Meanwhile, the `main.c` file also contains the test cases for the selected solution method.
>
> The `cfg` folder contains the configuration files for the common functions and solution methods.
>
> - The `compile_cfg.h` file is the configuration file for common functions. By toggling the `#define` macro, the corresponding common function can be enabled or disabled during compilation.
>
> - The `method_cfg.h` file is the configuration file for solution methods. By toggling the `#define` macro, the corresponding solution method can be enabled or disabled during compilation.
>
> The `doc` folder contains the documentation files and drawing sketches for the question.
>
> The `inc` folder contains the header files for the solution methods.
>
> The `src` folder contains the source files for the solution methods.
>
> - The `solution_name__method_name_xx.c` file is the source file for a specific solution method. By toggling the `#define` macro in the `method_cfg.h` file, the corresponding solution method can be enabled or disabled during compilation.
>
> For a complete example, please refer to the following file: `F02_Programming_Topics\F01_Data_Structure\01_Array\01_binarySearch\main.c`
>
> Flowchart source file: [compilation_structure.drawio](./F03_Misc/F02_Supplementary_Materials/compilation_structure.drawio) (hediet.vscode-drawio extension required)

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
> 1. Search for the header files in `/01_Common_Functions/inc/commonDef/` and `/01_Common_Functions/inc/` folders.
>
> 2. Search for the header files in `${fileDirname}/cfg/` and `${fileDirname}/inc/` folder.
>
> 3. Search and compile all the source files in `/01_Common_Functions/src/*.c` and `${fileDirname}/src/*.c` with `${fileDirname}/main.c` as the entry point.
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
> .\F00_Prerequisite\01_Clean_Exe\killExes.bat         /* windows system */
> ./F00_Prerequisite/01_Clean_Exe/killexe.sh           /* linux system */
> ```
>
> Source code: [killExes.bat](./F00_Prerequisite/01_Clean_Exe/killExes.bat) and [killExes.sh](./F00_Prerequisite/01_Clean_Exe/killExes.sh).

## Questions

> Now, please feel free to start the leetcode practice journey by selecting the desired programming topic in the [Programming_Topics](./F02_Programming_Topics/) folder.
>
> If there are any questions, please feel free to create an issue in the [Issues](https://github.com/ImChong/Practice_LeetCode_C/issues) or start a discussion in the [Discussions](https://github.com/ImChong/Practice_LeetCode_C/discussions).
