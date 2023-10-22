# Practice_LeetCode_C

C language leetcode practice guide:

- [Basics](00_Basics/) - common C language tips / functions
- [Programmercarl_Series](01_Programmercarl_Series/) - [代码随想录系列](https://programmercarl.com/)
- [Labuladong_Series](02_Labuladong_Series/) - [labuladong 的算法小抄系列](https://labuladong.github.io/algo/home/)
- [Real_World_Problem](03_Real_World_Problem/) - real world problem
- [Misc](04_Misc/) - miscellaneous
  - [Clean_Exe](04_Misc/00_Clean_Exe/) - clean all .exe files
  - [Programming_Notes](04_Misc/01_Programming_Notes/) - programming notes

## Versions

- gcc.exe (Rev7, Built by MSYS2 project) 13.1.0
- g++.exe (Rev7, Built by MSYS2 project) 13.1.0
- GNU gdb (GDB) 13.2

## Build & Run Code

### VSCode Native - Build & Run Current File

> In order to run source code in VSCode, select the main.c file that wish to run. Then click the following button in VSCode:
>
> ```txt
> Terminal -> Run Task... -> Build & Run Current File
> ```
>
> or
>
> ```txt
> Simply Press Ctrl+Shift+B
> ```
>
> for the source code to accomplish the above code please see [source code](.vscode/tasks.json).

### VSCode Extension - Code Runner

> for the `Code Runner` vscode extension to accomplish the above code please see [source code](.vscode/settings.json).

## Debug Code

> In order to debug source code in VSCode, select the .c file that wish to run.
> First Build & Run source code as the above section.
> Then click the following button in VSCode:
>
> ```txt
> Run and Debug (Ctil+Shift+D) -> (gdb) Debug Main
> ```
>
> or
>
> ```txt
> Simply Press F5
> ```
>
> for the source code to accomplish the above code please see [source code](.vscode/launch.json).

## Clean all .exe files

> ```txt
> ctrl+~ to open the terminal
> ```
>
> then
>
> ```txt
> Run .\04_Misc\00_Clean_Exe\killexe.bat        /* windows system */
> Run ./04_Misc/00_Clean_Exe/killexe.sh         /* linux system */
> ```

for the source code to accomplish the above code please see [source code](./04_Misc/00_Clean_Exe/).

## Progress

- [x] .
- [x] ├── 00_Basics
- [x] │   ├── 00_VScode_Settings
- [x] │   ├── 01_Common_Func
- [x] │   └── 02_Programming_Notes
- [x] ├── 01_Programmercarl_Series
- [x] │   ├── 01_Array
- [x] │   ├── 02_Linked_List
- [x] │   ├── 03_Hash_Table
- [ ] │   ├── 04_String
- [ ] │   ├── 05_Double_Pointer
- [x] │   ├── 06_Stack_Queue
- [x] │   ├── 07_Binary_Tree
- [ ] │   ├── 08_Backtracking
- [ ] │   ├── 09_Greedy
- [ ] │   ├── 10_Dynamic_Programming
- [ ] │   ├── 11_Monotone_Stack
- [ ] │   └── 12_Graph_Theory
- [x] ├── 02_Labuladong_Series
- [x] │   ├── 01_Linked_List
- [ ] │   ├── 02_Array
- [ ] │   ├── 03_Binary_Tree
- [ ] │   ├── 04_Dynamic_Programming
- [ ] │   ├── 05_Backtracking
- [ ] │   ├── 06_Breadth_First_Search
- [ ] │   ├── 07_Binary_Search
- [ ] │   ├── 08_Sliding_Window
- [ ] │   ├── 09_Buy_And_Sell
- [ ] │   ├── 10_House_Robber
- [ ] │   └── 11_N_Sum
- [x] ├── LICENSE
- [x] └── README.md
