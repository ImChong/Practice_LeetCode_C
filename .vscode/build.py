'''
FilePath     : \Practice_LeetCode_C\.vscode\build.py
Author       : Chong Liu
CreateDate   : 2023-11-04 00:23:08
LastEditors  : Chong Liu
LastEditTime : 2023-11-05 12:30:02
=================================================================================
Copyright (c) 2023 by Chong Liu, All Rights Reserved.
=================================================================================
Description  : python 编译指令，用于编译 ${fileDirname}/main.c
    如果存在 ${fileDirname}/src 文件夹，则编译 ${fileDirname}/src/*.c 和 ${fileDirname}/main.c
    如果不存在 ${fileDirname}/src 文件夹，则编译 ${fileDirname}/main.c
'''
import sys              # sys模块提供了一些函数和变量，可以通过它来访问与python解释器紧密相关的变量和函数
import os               # os模块提供了不少与操作系统相关联的函数
import subprocess       # subprocess模块允许你生成新的进程，连接它们的输入、输出、错误管道，并且获取它们的返回码

if __name__ == "__main__":
    print("Start compiling main.c ...")

    # sys.argv[0] = ${workspaceFolder}/.vscode/build.py
    gccPath = sys.argv[1]               # sys.argv[1] = gcc path
    workspacePath = sys.argv[2]         # sys.argv[2] = ${workspaceFolder}
    filePath = sys.argv[3]              # sys.argv[3] = ${fileDirname}
    mainPath = filePath + "/main.c"     # ${fileDirname}/main.c

    if not os.path.isfile(mainPath):                                # 如果没有 ${fileDirname}/main.c 则报错
        print("[" + mainPath + "] not exists")
        print("compilation failed!")
    else:                                                           # 如果存在 ${fileDirname}/main.c
        print("main.c exists. continue...")
        cmd = []
        if os.path.isdir(filePath + "/src"):                            # 如果存在 ${fileDirname}/src 文件夹
            print("src folder exists. continue...")
            cmd = [
                gccPath,
                "-fdiagnostics-color=always",
                "-I" + workspacePath + "/00_Basics/01_Common_Func/inc/",
                "-I" + workspacePath + "/00_Basics/01_Common_Func/inc/commonDef/",
                "-I" + filePath + "/cfg/",
                "-I" + filePath + "/inc/",
                "-g",
                workspacePath + "/00_Basics/01_Common_Func/src/*.c",
                filePath + "/src/*.c",
                mainPath,
                "-o",
                filePath + "/main.exe"
            ]
        else:                                                           # 如果不存在 ${fileDirname}/src 文件夹
            print("src folder not exists. continue...")
            cmd = [
                gccPath,
                "-fdiagnostics-color=always",
                "-I" + workspacePath + "/00_Basics/01_Common_Func/inc/",
                "-I" + workspacePath + "/00_Basics/01_Common_Func/inc/commonDef/",
                "-I" + filePath + "/cfg/",
                "-g",
                workspacePath + "/00_Basics/01_Common_Func/src/*.c",
                mainPath,
                "-o",
                filePath + "/main.exe"
            ]
        result = subprocess.run(cmd, capture_output=True, text=True)    # 执行编译指令
        if result.returncode != 0:                                      # 如果编译失败
            print(result.stderr)
            print("compilation failed!")
        else:                                                           # 如果编译成功
            print("compilation finished successfully!")