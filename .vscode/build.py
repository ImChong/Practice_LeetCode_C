'''
FilePath     : \Practice_LeetCode_C\.vscode\build.py
Author       : Chong Liu
CreateDate   : 2023-11-04 00:23:08
LastEditors  : Chong Liu
LastEditTime : 2023-11-04 20:25:05
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

    # sys.argv[0] = ${workspaceFolder}/.vscode/build.py
    # sys.argv[1] = gcc path
    # sys.argv[2] = ${workspaceFolder}
    # sys.argv[3] = ${fileDirname}

    filePath = sys.argv[3] + "/main.c"

    if os.path.isfile(filePath):
        print("main.c exists!")
        print("Compile finished successfully!")

    else:
        print("main.c not exists.")
        print("Compile failed!")


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

