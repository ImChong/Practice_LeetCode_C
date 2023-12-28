'''
FilePath     : \Practice_LeetCode_C\.vscode\build.py
Author       : Chong Liu
CreateDate   : 2023-11-04 00:23:08
LastEditors  : Chong Liu
LastEditTime : 2023-12-28 16:57:07
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
    print("Start compiling ...")

    # sys.argv[0] = ${workspaceFolder}/.vscode/build.py
    gccPath = sys.argv[1]               # sys.argv[1] = gcc path
    workspacePath = sys.argv[2]         # sys.argv[2] = ${workspaceFolder}
    filePath = sys.argv[3]              # sys.argv[3] = ${fileDirname}
    mainPath = filePath + "/main.c"     # ${fileDirname}/main.c

    if not os.path.isfile(mainPath):
        print("[" + mainPath + "] not exists, compilation failed!")     # 如果没有 ${fileDirname}/main.c 则报错
    elif not os.path.isdir(filePath + "/cfg"):
        print("cfg folder not exists, compilation failed!")
    elif not os.path.isdir(filePath + "/inc"):
        print("inc folder not exists, compilation failed!")
    elif not os.path.isdir(filePath + "/src"):
        print("src folder not exists, compilation failed!")
    else:   # 如果所需文件都存在
        print("file checks finished successfully! continue...")
        # 编译指令
        cmd = [
            gccPath,
            "-fdiagnostics-color=always",
            "-I" + workspacePath + "/00_Basics/01_Common_Func/inc/",
            "-I" + workspacePath + "/00_Basics/01_Common_Func/inc/commonDef/",
            "-I" + filePath + "/cfg/",
            "-I" + filePath + "/inc/",
            workspacePath + "/00_Basics/01_Common_Func/src/*.c",
            filePath + "/src/*.c",
            mainPath,
            "-g",
            "-o",
            filePath + "/main.exe"
        ]

        # 执行编译指令
        try:
            print("gcc compilation subprocess.runnning ...")
            result = subprocess.run(cmd, capture_output=True, text=True)

            if result.returncode == 0:
                print("subprocess.run compilation finished successfully!")

            else:
                print("An error occurred during compilation:")
                print(result.stderr)
                print("subprocess.run compilation failed!")

        except Exception as error:
            print("An error occurred during compilation:")
            print(str(error))
            print("subprocess.run compilation failed!")

    # 运行结束提示信息
    print("End compiling ...\n")
