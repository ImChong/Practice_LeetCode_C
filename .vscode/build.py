'''
FilePath     : \Practice_LeetCode_C\.vscode\build.py
Author       : Chong Liu
CreateDate   : 2023-11-04 00:23:08
LastEditors  : Chong Liu
LastEditTime : 2023-11-05 09:52:21
=================================================================================
Copyright (c) 2023 by Chong Liu, All Rights Reserved.
=================================================================================
Description  : python 编译指令
'''
import sys
import os
import subprocess

if __name__ == "__main__":
    print("Start compiling main.c ...")

    # print("sys.argv = ", sys.argv)
    # sys.argv[0] = ${workspaceFolder}/.vscode/build.py
    # sys.argv[1] = gcc path
    # sys.argv[2] = ${workspaceFolder}
    # sys.argv[3] = ${fileDirname}

    gccPath = sys.argv[1]
    workspacePath = sys.argv[2]
    mainPath = sys.argv[3] + "/main.c"

    if not os.path.isfile(mainPath):                # 如果不存在 main.c
        print("[" + mainPath + "] not exists")
        print("Compile failed!")
    else:                                           # 如果存在 main.c
        print("main.c exists!")

        if os.path.isdir(sys.argv[3] + "/src"):         # 如果存在 src 文件夹
            print("src folder exists!")
        else:                                           # 如果不存在 src 文件夹
            print("src folder not exists!")

        print("Compile finished successfully!")


    # 如果没有 ${fileDirname}/main.c 则报错

    # 如果有 ${fileDirname}/src 文件夹则编译
        # gcc
        #     "-fdiagnostics-color=always",
        #     "-I${workspaceFolder}/00_Basics/01_Common_Func/inc/",
        #     "-I${workspaceFolder}/00_Basics/01_Common_Func/inc/commonDef/",
        #     "-I${fileDirname}/cfg/",
        #     "-I${fileDirname}/inc/",
        #     "-g",
        #     "${workspaceFolder}/00_Basics/01_Common_Func/src/*.c",
        #     "${fileDirname}/src/*.c",
        #     "main.c",
        #     "-o",
        #     "${fileDirname}/main.exe"

    # 如果没有 ${fileDirname}/src 文件夹则编译
        # gcc
        #     "-fdiagnostics-color=always",
        #     "-I${workspaceFolder}/00_Basics/01_Common_Func/inc/",
        #     "-I${workspaceFolder}/00_Basics/01_Common_Func/inc/commonDef/",
        #     "-g",
        #     "${fileDirname}/src/*.c",
        #     "main.c",
        #     "-o",
        #     "${fileDirname}/main.exe"

